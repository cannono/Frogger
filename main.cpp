#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <vector>

using namespace std;
using namespace sf;

struct Player
{
  int xpos, ypos;
};

int main()
{



  RenderWindow window(VideoMode(950,650), "Frogger");

  //Clock clock;

  Texture t1, t2, t3, t4, t5, t6, t7, t8, t9, t10;
  if(!t1.loadFromFile("textures/background.png")) cout << "Loading texture failed" << endl;
  else t1.loadFromFile("textures/background.png");

  if(!t2.loadFromFile("textures/frog.png")) cout << "Loading texture failed" << endl;
  else t2.loadFromFile("textures/frog.png");

  if(!t3.loadFromFile("textures/three.png")) cout << "Loading texture failed" << endl;
  else t3.loadFromFile("textures/three.png");

  if(!t4.loadFromFile("textures/four.png")) cout << "Loading texture failed" << endl;
  else t4.loadFromFile("textures/four.png");

  if(!t5.loadFromFile("textures/two.png")) cout << "Loading texture failed" << endl;
  else t5.loadFromFile("textures/two.png");

  if(!t6.loadFromFile("textures/trailer.png")) cout << "Loading texture failed" << endl;
  else t6.loadFromFile("textures/trailer.png");

  if(!t7.loadFromFile("textures/car1.png")) cout << "Loading texture failed" << endl;
  else t7.loadFromFile("textures/car1.png");

  if(!t8.loadFromFile("textures/car2.png")) cout << "Loading texture failed" << endl;
  else t8.loadFromFile("textures/car2.png");

  if(!t9.loadFromFile("textures/moto.png")) cout << "Loading texture failed" << endl;
  else t9.loadFromFile("textures/moto.png");

  if(!t10.loadFromFile("textures/truck.png")) cout << "Loading texture failed" << endl;
  else t10.loadFromFile("textures/truck.png");

  Sprite background(t1);
  Sprite frog(t2);
  Sprite log3(t3);
  Sprite log4(t4);
  Sprite log_2(t5);

  Sprite trailer(t6);
  Sprite car1(t7);
  Sprite car2(t8);
  Sprite moto(t9);
  Sprite truck(t10);

  Player Frogger = {450,600};

  vector<Sprite> medium_logs;
  log3.setPosition(0,50);
  medium_logs.push_back(log3);
  log3.setPosition(400,50);
  medium_logs.push_back(log3);
  log3.setPosition(800,50);
  medium_logs.push_back(log3);

  vector<Sprite> large_logs;
  log4.setPosition(100,150);
  large_logs.push_back(log4);
  log4.setPosition(700, 150);
  large_logs.push_back(log4);

  vector<Sprite> small_logs;
  log_2.setPosition(350,200);
  small_logs.push_back(log_2);
  log_2.setPosition(650,200);
  small_logs.push_back(log_2);
  log_2.setPosition(100,200);
  small_logs.push_back(log_2);

  vector<Sprite> trailers;
  trailer.setPosition(700,850);
  trailers.push_back(trailer);
  trailer.setPosition(200,850);
  trailers.push_back(trailer);

  vector<Sprite> carOnes;
  car1.setPosition(400,800);
  carOnes.push_back(car1);
  car1.setPosition(650,800);
  carOnes.push_back(car1);

  vector<Sprite> carTwos;
  car2.setPosition(100,750);
  carTwos.push_back(car2);
  car2.setPosition(450,750);
  carTwos.push_back(car2);
  car2.setPosition(800,750);
  carTwos.push_back(car2);

  vector<Sprite> motos;
  moto.setPosition(150,700);
  motos.push_back(moto);
  moto.setPosition(700,700);
  motos.push_back(moto);

  vector<Sprite> trucks;
  truck.setPosition(200,650);
  trucks.push_back(truck);
  truck.setPosition(650,650);
  trucks.push_back(truck);
  truck.setPosition(850,650);
  trucks.push_back(truck);



  frog.setPosition(Frogger.xpos, Frogger.ypos);
  background.setPosition(0,0);


  window.setKeyRepeatEnabled(false);
  while (window.isOpen())
  {
    Event Event;
    while(window.pollEvent(Event))
    {
      switch (Event.type)
      {
        case Event::Closed:
          window.close();
          break;
        case Event::KeyPressed:
          if(Event.key.code == Keyboard::Up || Event.key.code == Keyboard:: W) Frogger.ypos +=-50;

          if(Event.key.code == Keyboard::Down || Event.key.code == Keyboard:: S) Frogger.ypos += 50;

          if(Event.key.code == Keyboard::Left || Event.key.code == Keyboard:: A) Frogger.xpos +=-50;

          if(Event.key.code == Keyboard::Right || Event.key.code == Keyboard:: D) Frogger.xpos += 50;

          break;
      }
    }

      frog.setPosition(Frogger.xpos, Frogger.ypos);

      window.clear();
      window.draw(background);

      for(int i=0; i < medium_logs.size(); i++)
      {
        window.draw(medium_logs[i]);
        medium_logs[i].move(2,0);
        if(medium_logs[i].getPosition().x >= 950) medium_logs[i].setPosition(-150,50);
      }

      for(int k=0; k < large_logs.size(); k++)
      {
        window.draw(large_logs[k]);
        large_logs[k].move(3,0);
        if(large_logs[k].getPosition().x >= 950) large_logs[k].setPosition(-250,150);
      }

      for(int j=0; j < small_logs.size(); j++)
      {
        window.draw(small_logs[j]);
        small_logs[j].move(1,0);
        if(small_logs[j].getPosition().x >= 950) small_logs[j].setPosition(-100,200);
      }

      for(int l=0; l < trailers.size(); l++)
      {
        window.draw(trailers[l]);
        trailers[l].move(-2,0);
        if(trailers[l].getPosition().x <= 0) trailers[l].setPosition(1050,550);
      }

      for(int m=0; m < carTwos.size(); m++)
      {
        window.draw(carTwos[m]);
        carTwos[m].move(1,0);
        if(carTwos [m].getPosition().x >= 950) carTwos[m].setPosition(-50,500);
      }

      for(int p=0; p < carOnes.size(); p++)
      {
        window.draw(carOnes[p]);
        carOnes[p].move(-1,0);
        if(carOnes[p].getPosition().x <= 0) carOnes[p].setPosition(1000,450);
      }

      for(int t=0; t < motos.size(); t++)
      {
        window.draw(motos[t]);
        motos[t].move(3,0);
        if(motos[t].getPosition().x >= 950) motos[t].setPosition(-50,400);
      }

      for(int d=0; d < trucks.size(); d++)
      {
        window.draw(trucks[d]);
        trucks[d].move(-3,0);
        if(trucks[d].getPosition().x <= 0) trucks[d].setPosition(1050,350);
      }




      window.draw(frog);

      window.display();


    }



  return 0;
}
