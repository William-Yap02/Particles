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
    while (m_Window.open())
    {
        clock.restart();
        input();
	    update(float dtAsSeconds);
	    draw();
    }




}