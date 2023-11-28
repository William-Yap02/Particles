#include "Engine.h"

Engine::Engine()
{
    int desktopWidth = VideoMode::getDesktopMode().width;
    int desktopHeight = VideoMode::getDesktopMode().height;
    m_Window.create(VideoMode(desktopWidth, desktopHeight), "Particles", Style::Default);

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
        clock.restart();
        input();
	    update(float dtAsSeconds);
	    draw();
    }
}
 void Engine::input()
{
     while (m_Window.isOpen())
    {   
    Event event;
    while (m_Window.pollEvent(event))
	    {
            if (event.type == Event::Closed)
            {
        // Qut the program when the window is closed
				m_Window.close();
            }
            else if (event.type == Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == Mouse::Left)
                {
                    for (int i=0;i<5;i++)
                    {
                        Particle particle; 
                        int max = 50;
                        int min = 25;
                        int range = max - min + 1;
                        int numPoints = rand() % range + min;
                        Particle(RenderTarget& target, int numPoints, Vector2i mouseClickPosition);
                    }
                }
            }i

        }
    }
 }