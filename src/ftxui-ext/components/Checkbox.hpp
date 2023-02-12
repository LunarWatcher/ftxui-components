#pragma once

#include "ftxui/component/component.hpp"
#include <ftxui/component/event.hpp>
#include <ftxui/dom/node.hpp>
#include <ftxui/util/ref.hpp>

#include "state/ComponentState.hpp"

namespace ftxui::ext {

struct CheckboxOption {
    static CheckboxOption Simple();
    
    std::function<Element(const DynLabelState&)> transform;
    std::function<void()> onChange = nullptr;

    void notify();
};

class CheckboxImpl : public ftxui::ComponentBase {
protected:
    ftxui::Element label;
    bool* isChecked;
    bool hovered = false;

    // TODO: can this be replaced with std::ref? Not sure why there's an entire custom class for a thing
    // that seems to already exist, but if it is identical, I wanna get rid of it in the extension files.
    ftxui::Ref<CheckboxOption> opt;
    ftxui::Box box;

public:
    CheckboxImpl(const std::string& label, bool* isChecked, ftxui::Ref<CheckboxOption> opt);
    CheckboxImpl(ftxui::Element label, bool* isChecked, ftxui::Ref<CheckboxOption> opt);

    virtual ftxui::Element Render() override;
    virtual bool OnEvent(ftxui::Event e) override;

    virtual bool Focusable() const override { return true; }
};

}
