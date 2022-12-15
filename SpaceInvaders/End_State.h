#include "State.h"
#include "Menu_State.h"

class End_State : public State {
public:
/*
 * The State when we lose the game. 
 * We can only return to the Menu from here.
 */
    
    End_State(const shared_ptr<State>& win = nullptr);
    sf::Window window;

    shared_ptr<State> update(sf::Time dt) override;
    void on_key_press(sf::Keyboard::Key key) override;
    void render(sf::RenderWindow &window) override;

    private:
    using Action = std::function<shared_ptr<State>()>;
    struct Entry {
        sf::Text text;
        float color;
        Action go_to_menu;
    };
    sf::Font font;
    Entry entry;
    bool enter_pressed;
    sf::Time delay;
    shared_ptr<State> background;
    void set_entry(const string& text, Action action);
    
};