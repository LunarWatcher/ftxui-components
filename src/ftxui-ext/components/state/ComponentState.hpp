#include <ftxui/dom/node.hpp>
namespace ftxui::ext {

/**
 * EntryState, but with an element label
 */
struct DynLabelState {
    ftxui::Element label;
    bool state;
    bool active;
    bool focused;
};

}
