#include "Common.hpp"
#include "Math.hpp"
#include "Canvas.hpp"
#include "Game.hpp"
#include "Player.hpp"
#include "Blip.hpp"
#include "Particle.hpp"

CGame CurGame;
CPlayer CurPlayer;
CBlip CurBlip;
uint64_t Difficulty = 50;
bool PreviouslyPressed = false;
std::list<CParticle> particles;
std::list<std::tuple<CVec2, bool>> holes;
auto timer = std::chrono::steady_clock::now();

void EventUpdate(sf::Event event, sf::RenderWindow * window)
{
	switch(event.type)
	{
	case sf::Event::MouseButtonPressed:
	{
		switch(event.mouseButton.button)
		{
		case sf::Mouse::Left:
		{
			for (int i = 0; i < 100; ++i)
				particles.push_back(CParticle(CVec2(event.mouseButton.x + CMath::RandFloat(-5.f, 5.f), event.mouseButton.y + CMath::RandFloat(-5.f, 5.f)), CVec2(15.f, CMath::RandFloat(-0.5f, 0.5f))));
			break;
		}
		case sf::Mouse::Right:
		{
			holes.emplace_back(std::make_tuple( CVec2(event.mouseButton.x, event.mouseButton.y), true ));
			break;
		}
		case sf::Mouse::Middle:
		{
			holes.emplace_back(std::make_tuple(CVec2(event.mouseButton.x, event.mouseButton.y), false));
			break;
		}
		case sf::Mouse::XButton1:
		{
			break;
		}
		case sf::Mouse::XButton2:
		{
			break;
		}
		default:
		{
			break;
		}
		}
		break;
	}
	case sf::Event::KeyPressed:
	{
		switch(event.key.code)
		{
		case sf::Keyboard::A:
		{
			break;
		}
		case sf::Keyboard::B:
		{
			break;
		}
		case sf::Keyboard::C:
		{
			break;
		}
		case sf::Keyboard::D:
		{
			break;
		}
		case sf::Keyboard::E:
		{
			break;
		}
		case sf::Keyboard::F:
		{
			break;
		}
		case sf::Keyboard::G:
		{
			break;
		}
		case sf::Keyboard::H:
		{
			break;
		}
		case sf::Keyboard::I:
		{
			break;
		}
		case sf::Keyboard::J:
		{
			break;
		}
		case sf::Keyboard::K:
		{
			break;
		}
		case sf::Keyboard::L:
		{
			break;
		}
		case sf::Keyboard::M:
		{
			break;
		}
		case sf::Keyboard::N:
		{
			break;
		}
		case sf::Keyboard::O:
		{
			break;
		}
		case sf::Keyboard::P:
		{
			switch(CurGame.GameState)
			{
			case CGame::State::INGAME:
			{
				CurGame.GameState = CGame::State::PAUSED;
				break;
			}
			case CGame::State::PAUSED:
			{
				CurGame.GameState = CGame::State::INGAME;
				break;
			}
			default:
			{
				break;
			}
			}
			break;
		}
		case sf::Keyboard::Q:
		{
			break;
		}
		case sf::Keyboard::R:
		{
			break;
		}
		case sf::Keyboard::S:
		{
			break;
		}
		case sf::Keyboard::T:
		{
			break;
		}
		case sf::Keyboard::U:
		{
			break;
		}
		case sf::Keyboard::V:
		{
			break;
		}
		case sf::Keyboard::W:
		{
			break;
		}
		case sf::Keyboard::X:
		{
			break;
		}
		case sf::Keyboard::Y:
		{
			break;
		}
		case sf::Keyboard::Z:
		{
			if (!holes.empty())
				holes.pop_back();
			break;
		}
		case sf::Keyboard::Up:
		{
			break;
		}
		case sf::Keyboard::Down:
		{
			break;
		}
		case sf::Keyboard::Left:
		{
			break;
		}
		case sf::Keyboard::Right:
		{
			break;
		}
		case sf::Keyboard::Return:
		{
			if (CurGame.GameState == CGame::State::MENU || CurGame.GameState == CGame::State::LOSE)
				CurGame.GameState = CGame::State::INGAME;

			break;
		}
		default:
		{
			break;
		}
		}
		break;
	}
	case sf::Event::Closed:
	{
		window->close();
		break;
	}
	}
}


void Update(size_t milliseconds)
{
	timer = std::chrono::steady_clock::now();

	switch(CurGame.GameState)
	{
		case CGame::State::MENU:
		{
			break;
		}
		case CGame::State::LOSE:
		{
			break;
		}
		case CGame::State::INGAME:
		{
			auto i = std::begin(particles);

			while (i != std::end(particles)) 
			{
				static bool delet = false;

				auto & p = *i;

				if (p.Pos.x > 1600.f || p.Pos.x < 0.f || p.Pos.y > 900.f || p.Pos.y < 0.f)
				{
					particles.erase(i++);
				}
				else
				{
					CVec2 total(0.f, 0.f);

					for (const auto h : holes)
					{
						CVec2 temp = std::get<1>(h) ? std::get<0>(h) - p.Pos : p.Pos - std::get<0>(h);

						if (temp.LengthSqr() < 100.f)
						{
							particles.erase(i++);
							delet = true;
							break;
						}

						temp /= temp.LengthSqr() * temp.Length();

						total += temp;
					}

					if(delet)
					{
						delet = false;
						continue;
					}

					p.velocity += total * 1000.f;

					p.Pos += p.velocity * milliseconds * 0.016f;

					++i;
				}
			}

			break;
		}
		case CGame::State::PAUSED:

			break;
	}
}

void Render(sf::RenderWindow * Win)
{
	NCanvas::Win = Win;

	switch(CurGame.GameState)
	{
	case CGame::State::MENU:
		NCanvas::Rect(CVec2(0.f, 0.f), CVec2(1600.f, 900.f), CColour(0, 255, 0));
		NCanvas::Text("Welcome to Particle!", 20, CVec2(650.f, 400.f), CColour(255, 255, 255), CColour(0, 0, 0), false,1.f);
		NCanvas::Text("Press Enter to Play", 20, CVec2(700.f, 450.f), CColour(255, 255, 255), CColour(0, 0, 0));
		break;
	case CGame::State::INGAME:
	{
		NCanvas::Rect(CVec2(0.f, 0.f), CVec2(1600.f, 900.f), CColour(0, 0, 0));

		for (auto p : particles)
		{
			NCanvas::Line(p.Pos, p.Pos - p.velocity, CColour(255, 255, 255));

			NCanvas::Rect(p.Pos - CVec2(2.f, 2.f), CVec2(4.f, 4.f), CHSB(CMath::RandFloat(0.f, 1.f), 1.f, 1.f).ToColour());
		}

		for (auto h : holes)
		{
			NCanvas::OutlinedRect(std::get<0>(h) - CVec2(5.f, 5.f), CVec2(10.f, 10.f), std::get<1>(h) ? CColour(0, 0, 0) : CColour(255, 255, 255), std::get<1>(h) ? CColour(255, 255, 255) : CColour(0, 0, 0));
		}

		break;
	}
	case CGame::State::LOSE:
		NCanvas::Rect(CVec2(0.f, 0.f), CVec2(1600.f, 900.f), CColour(255, 0, 0));

		NCanvas::Text("You Lose", 20, CVec2(730.f, 400.f), CColour(255, 255, 255), CColour(255, 0, 0));
		NCanvas::Text(std::to_string(CurPlayer.Blocks.size()), 50, CVec2(850.f, 400.f), CColour(CMath::RandInt(70, 200), CMath::RandInt(70, 200), CMath::RandInt(70, 200)), CColour(0, 0, 0), false, 1.f);
		NCanvas::Text("Press Enter to Play Again", 20, CVec2(700.f, 450.f), CColour(255, 255, 255), CColour(255, 0, 0));
		break;
	case CGame::State::PAUSED:
		NCanvas::Rect(CVec2(0.f, 0.f), CVec2(1600.f, 900.f), CColour(255, 255, 255, 255));

		NCanvas::Text("Paused - AVAVAVAVAVA", 20, CVec2(730.f, 400.f), CColour(0, 0, 0), CColour(255, 0, 0));
		NCanvas::Text("Press P to Resume", 20, CVec2(710.f, 450.f), CColour(255, 0, 0), CColour(255, 0, 0));
		break;
	}
}

int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	sf::RenderWindow window(sf::VideoMode(1600, 900), "Particle");

	timer = std::chrono::steady_clock::now();

	CurGame.GameState = CGame::State::INGAME;

	while(window.isOpen())
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			EventUpdate(event, &window);
		}

		window.clear();

		Update(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - timer).count());

		Render(&window);

		NCanvas::Text(std::to_string(particles.size()), 20, CVec2(50.f, 50.f), CColour(255, 255, 255), CColour(0, 0, 0), false, 2.f);
		NCanvas::Text(std::to_string(holes.size()), 20, CVec2(50.f, 80.f), CColour(255, 255, 255), CColour(0, 0, 0), false, 2.f);

		window.display();

		Sleep(CMath::Max(0LL, static_cast<long long>(static_cast<long long>(1000.f / CurGame.tick_rate)
			                 - std::chrono::duration_cast<std::chrono::milliseconds>(
				                 std::chrono::steady_clock::now() - timer).count())));


	}

	return 0;
}

