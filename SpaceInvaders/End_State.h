#include "State.h"
#include "Menu_State.h"

class End_State : public State {
public:
/*
 * The State when we win or lose the game. 
 * We can only return to the Menu from here.
 * 
 */
    
    /*
     * We can check if the result is win or loss in
     * the constructor.
     * */
    End_State(const shared_ptr<State>& win = nullptr);
    sf::Window window;

    /* 
     * Update this state
     * */
    shared_ptr<State> update(sf::Time dt) override;
    
    /*
     * Take action on a key press
     * */
    void on_key_press(sf::Keyboard::Key key) override;
    
    /*
     * Render the material on screen
     * */
    void render(sf::RenderWindow &window) override;

    private:

    /*
     * The action to take
     * */
    using Action = std::function<shared_ptr<State>()>;
    
    /*
     * Describes a menu entry or "option"
     * */
    struct Entry {
        sf::Text text;
        float color;
        Action go_to_menu;
    };

    /*
     * For style and rendering
     * */
    sf::Font font;
    Entry entry;
    bool enter_pressed;
    sf::Time delay;

    /*
     * Maintain our background
     * */
    shared_ptr<State> background;

    /*
     * For single entry options as opposed
     * to Menu_States ability for several options
     * */
    void set_entry(const string& text, Action action);
    
};
