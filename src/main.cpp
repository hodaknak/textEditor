#include <memory>  // for shared_ptr, allocator, __shared_ptr_access
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <filesystem>

#include "ftxui/component/captured_mouse.hpp"  // for ftxui
#include "ftxui/component/component.hpp"  // for Renderer, ResizableSplitBottom, ResizableSplitLeft, ResizableSplitRight, ResizableSplitTop

#include "ftxui/component/component_base.hpp"      // for ComponentBase
#include "ftxui/component/screen_interactive.hpp"  // for ScreenInteractive
#include "ftxui/dom/elements.hpp"  // for Element, operator|, text, center, border
#include "ftxui/component/component_options.hpp"

#include "styles.h"
#include "file.h"

std::filesystem::path get_path(const std::string &fileName) {
    const auto path = std::filesystem::path(fileName);

    return absolute(path);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Expected a file path" << std::endl;
        return 1;
    }

    ftxui::ScreenInteractive screen = ftxui::ScreenInteractive::Fullscreen();

    const std::filesystem::path filePath = get_path(argv[1]);

    std::vector<File> files;
    std::string fileName = filePath.stem().string() + filePath.extension().string();

    if (filePath.has_extension()) {
        files = {File(filePath)};
    } else {
        files = File::openFolder(filePath);
    }

    File* currentFile = &files[0];
    std::string code = currentFile->getData();

    // actual text editor
    ftxui::InputOption editorOption = styles::editor();

    editorOption.on_change = [&]() {
        currentFile->setData(code);
    };

    ftxui::Component editor = ftxui::Input(&code, "", editorOption);

    std::vector<ftxui::Component> fileButtons;

    fileButtons.reserve(files.size());
    for (auto& file : files) {
        fileButtons.push_back(ftxui::Button(file.getName(), [&] {
            currentFile = &file;
            code = currentFile->getData();
        }));
    }

    // sidebar
    ftxui::Component left = ftxui::Container::Vertical(fileButtons);

    int left_size = 20;

    ftxui::Component container = editor;
    container = ResizableSplitLeft(left, container, &left_size);

    ftxui::Component saveButton = ftxui::Button("Save", [&] { currentFile->write(); }, styles::saveButton());
    ftxui::Component exitButton = ftxui::Button("Exit", [&] { screen.Exit(); }, styles::exitButton());

    ftxui::Component buttons = ftxui::Container::Horizontal({saveButton, exitButton});

    auto editorDocument = [&] {
        return ftxui::window(ftxui::text(currentFile->getName()), container->Render()) | ftxui::flex;
    };

    auto footerDocument = [&] {
        return ftxui::border(
            ftxui::hbox(
                ftxui::text(filePath.string()) | ftxui::center,
                ftxui::filler(),
                buttons->Render()
            )
        );
    };

    auto renderer = ftxui::Container::Vertical({
        Renderer(container, editorDocument),
        Renderer(buttons, footerDocument)
    });

    screen.Loop(renderer);
}
