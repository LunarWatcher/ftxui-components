#pragma once

#include "ftxui/component/component.hpp"
#include <ftxui/util/ref.hpp>

namespace fxtui::ext::components {

class CheckboxImpl : public ftxui::ComponentBase {
public:
    CheckboxImpl(ftxui::ConstStringRef label, bool* state, ftxui::Ref<ftxui::CheckboxOption> opt);
    
};

}
