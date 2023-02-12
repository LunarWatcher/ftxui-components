# Ftxui components

Many of the standard ftxui components are arguably severely lacking. This mini-library exists to bridge the gap of useful and flexible components.

This library requires C++20, and is targeted at ftxui's master branch, due to 3.0.0 being [broken on Clang 14/15](https://github.com/ArthurSonzogni/FTXUI/pull/421), and no other versions existing at the time of writing.

**NOTE:** This library does NOT include ftxui itself! It has to be installed and linked separately. This is done to avoid version conflicts and build system integration fuckery. Get it yourself with Your Favorite Installation Method:tm:

## Compatibility notes

This is a library built on top of ftxui, and is obviously compatible with ftxui itself. However, there isn't complete compatibility in functional use.

In order to extend many of the components, they've had to be rewritten from scratch. Internally, many of the components rely on specific structs that have been changed. For instance, both Buttons and Checkboxes rely on a struct called EntryState, a struct that had to have a single type altered. This broke compatiblity with all the ButtonOptions.

Additionally, due to name choices, there are overlaps with the mainline names. Therefore, you should not `using namespace ftxui::ext`; if you want to use a `using namespace` to shorten your calls, use `using namespace ftxui;` and refer to all the extensions via the `ext::` namespace.

However, certain names have been altered to fully differentiate between builtins and expansions declared by this library. For instance, the altered CheckboxOption is called `ExtCheckboxOption`. This means that the library will be lacking in some areas, as feature parity is annoying to accomplish alone. (Read: PRs are welcome)

Also worth noting that using both namespaces will likely cause compiler errors due to the aforementioned name conflicts. You can do one, just not both.

### Convention differences

Because this is primarily intended as a supplement to the mainline ftxui components, this library follows my own naming conventions, and code organisation conventions. This doesn't mean much, but any extended use migration from mainline components to extended components may require additional changes.

