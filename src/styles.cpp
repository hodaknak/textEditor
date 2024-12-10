#include "styles.h"

#include <iostream>

#include "ftxui/component/component.hpp"

ftxui::InputOption styles::editor() {
    ftxui::InputOption editorOption = ftxui::InputOption::Spacious();

    editorOption.transform = [](const ftxui::InputState &state) {
        return state.element;
    };

    return editorOption;
}

ftxui::ButtonOption styles::saveButton() {
    ftxui::ButtonOption saveButtonOption = ftxui::ButtonOption::Simple();

    saveButtonOption.transform = [](const ftxui::EntryState &state) {
        ftxui::Element element = ftxui::text(state.label);

        return element | ftxui::border | ftxui::center;
    };

    return saveButtonOption;
}

ftxui::ButtonOption styles::exitButton() {
    ftxui::ButtonOption saveButtonOption = ftxui::ButtonOption::Simple();

    saveButtonOption.transform = [](const ftxui::EntryState &state) {
        ftxui::Element element = ftxui::text(state.label);

        return element | ftxui::border | ftxui::center;
    };

    return saveButtonOption;
}
