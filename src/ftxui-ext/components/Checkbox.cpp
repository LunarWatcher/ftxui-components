#include "Checkbox.hpp"
#include <ftxui/component/event.hpp>
#include <tuple>

namespace ftxui::ext {

CheckboxImpl::CheckboxImpl(const std::string& label, bool* isChecked, ftxui::Ref<CheckboxOption> opt) : CheckboxImpl(ftxui::text(label), isChecked, opt) {}
CheckboxImpl::CheckboxImpl(ftxui::Element label, bool* isChecked, ftxui::Ref<CheckboxOption> opt) : label(label), isChecked(isChecked), opt(opt) {
    if (isChecked == nullptr) throw std::runtime_error("Need a non-null data pointer");
}
    


ftxui::Element CheckboxImpl::Render() {
    // Awkward as fuck, but these can be heavy calls. Caching is good
    bool isActive = Active();
    bool isFocused = Focused();

    auto focusType = isFocused ? focus : isActive ? select : nothing;

    auto state = DynLabelState {
        label,
        *isChecked,
        isActive,
        isFocused || hovered
    };

    auto element = (opt->transform ? opt->transform : CheckboxOption::Simple().transform)(state);
    return element | focusType | reflect(box);

}

bool CheckboxImpl::OnEvent(ftxui::Event event) {
    if (!CaptureMouse(event)) return false;

    if (event.is_mouse()) {
        hovered = box.Contain(event.mouse().x, event.mouse().y);
        if (!hovered) return false;

        if (event.mouse().button == Mouse::Left && event.mouse().motion == Mouse::Pressed) {
            *isChecked = !*isChecked;
            opt->notify();
            return true;
        }
    } else {
        hovered = false;
        if (event == Event::Character(' ') || event == Event::Return) {
            *isChecked = !*isChecked;
            opt->notify();
            TakeFocus();
            return true;
        }
    }

    return false;
}

// CheckboxOption {{{
// Implementations {{{
//
// }}}
// Functions {{{
void CheckboxOption::notify() {
    if (onChange) onChange();
}
// }}}
// }}}
}
