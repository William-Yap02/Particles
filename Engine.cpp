#include "Engine.h"

Engine::Engine()
{
    m_Window.create(VideoMode::getDesktopMode(), "Particles", Style::Default);
}

void Engine::run()
{
    Clock clock; //Construct a local Clock object to track time per frame
    cout << "Starting Particle unit tests..." << endl;
    Particle p(m_Window, 4, { (int)m_Window.getSize().x / 2, (int)m_Window.getSize().y / 2 });
    p.unitTests();
    cout << "Unit tests complete.  Starting engine..." << endl;
    while (m_Window.isOpen()) //while window is open run private members
    {
        Time time = clock.restart();
        float timeSeconds = time.asSeconds();
        input();
	    update(timeSeconds);
	    draw();
    }
}

void Engine::input()
{ 
    Event event;
    while (m_Window.pollEvent(event))
	{
        if (event.type == Event::Closed)
        {
            // Qut the program when the window is closed
			m_Window.close();
        }
        else if (event.type == Event::KeyPressed)
        {
            if (event.key.code == Keyboard::Escape)
            {
                m_Window.close();
            }
        }
        else if (event.type == Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == Mouse::Left)
            {
                for (int i = 0; i < 5; i++)
                {
                    int max = 50;
                    int min = 25;
                    int range = max - min + 1;
                    int numPoints = rand() % range + min;
                    Vector2i mousePosition = Mouse::getPosition(m_Window);
                    Particle particle(m_Window, numPoints, mousePosition);
                    m_particles.push_back(particle);
                }
            }
        }
    }
}

void Engine::update(float dtAsSeconds)
{
    for (int i = 0; i < m_particles.size(); )
    {
        if (m_particles[i].getTTL() > 0.0)
        {
            m_particles[i].update(dtAsSeconds);
            i++;
        }
        else 
        {
            m_particles.erase(m_particles.begin() + i);
        }
    }
}

void Engine::draw()
{
    m_Window.clear();

    for (Particle particle : m_particles)
    {
        m_Window.draw(particle);
    }

    m_Window.display();
}