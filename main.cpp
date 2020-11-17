#include "Player.h"
#include"Enemy.h"
#include"State_Machine.h"
#include"State_Base.h"
int main()
{
    State_Machine::GetInstance()->ChangeState(StateTypes::STATE_Info);

    sf::RenderWindow* window= new RenderWindow(sf::VideoMode(800, 800), "Save Cabbage! by Huy Pham", sf::Style::Close);
    State_Base::window = window;
    window->setFramerateLimit(60);

    sf::CircleShape shape(100.f);


    float currentTime = 0.f;
    while (window->isOpen())
    {
        if (State_Machine::GetInstance()->NeedToChangeState()) {
            (State_Machine::GetInstance()->PerformStateChange());
        }
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::EventType::Closed)
            {
                window->close();
            }
        }
        sf::Vector2f v(200.f , 1000.f*cos(10.f * currentTime)+10.f);
        shape.move(v*1.f/100.f);
        currentTime += 1.f / 100.f;

        State_Machine::GetInstance()->CurrentState()->Update(1.f/100.f);
        window->clear();
        State_Machine::GetInstance()->CurrentState()->Draw(window);
       // window->draw(shape);
        window->display();
    }
    
    return 0;
}