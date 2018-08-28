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

void load_time(vector<Sprite> &thyme, Sprite bar, Sprite time_)
{
  thyme.erase(thyme.begin(), thyme.begin() + thyme.size());
  thyme.push_back(time_);
  for(int i = 0; i <= 20; ++i)
  {
    bar.setPosition(950 - (i*10),650);
    thyme.push_back(bar);
  }
}


void reset_frog(Player &Frogger)
{
  Frogger.xpos = 450;
  Frogger.ypos = 600;
}

int main()
{

  RenderWindow window(VideoMode(950,700), "Frogger");

  //Clock clock;

  Texture t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15;
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

  if(!t11.loadFromFile("textures/lilly2.png")) cout << "Loading texture failed" << endl;
  else t11.loadFromFile("textures/lilly2.png");

  if(!t12.loadFromFile("textures/lilly3.png")) cout << "Loading texture failed" << endl;
  else t12.loadFromFile("textures/lilly3.png");

  if(!t13.loadFromFile("textures/game-over.png")) cout << "Loading texture failed" << endl;
  else t13.loadFromFile("textures/game-over.png");

  if(!t14.loadFromFile("textures/bar.png")) cout << "Loading texture failed" << endl;
  else t14.loadFromFile("textures/bar.png");

  if(!t15.loadFromFile("textures/time.png")) cout << "Loading texture failed" << endl;
  else t15.loadFromFile("textures/time.png");

  Sprite background(t1);
  Sprite gameOver(t13);
  Sprite bar(t14);
  Sprite time_(t15);


  Sprite frog(t2);
  Sprite log3(t3);
  Sprite log4(t4);
  Sprite log_2(t5);
  Sprite lilly2(t11);
  Sprite lilly3(t12);

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

  vector<Sprite> small_lilly;
  lilly2.setPosition(50,100);
  small_lilly.push_back(lilly2);
  lilly2.setPosition(350,100);
  small_lilly.push_back(lilly2);
  lilly2.setPosition(650,100);
  small_lilly.push_back(lilly2);
  lilly2.setPosition(900,100);
  small_lilly.push_back(lilly2);

  vector<Sprite> med_lilly;
  lilly3.setPosition(150,250);
  med_lilly.push_back(lilly3);
  lilly3.setPosition(500,250);
  med_lilly.push_back(lilly3);
  lilly3.setPosition(800,250);
  med_lilly.push_back(lilly3);

  vector<Sprite> trailers;
  trailer.setPosition(700,550);
  trailers.push_back(trailer);
  trailer.setPosition(200,550);
  trailers.push_back(trailer);

  vector<Sprite> carOnes;
  car1.setPosition(400,500);
  carOnes.push_back(car1);
  car1.setPosition(650,500);
  carOnes.push_back(car1);

  vector<Sprite> carTwos;
  car2.setPosition(100,450);
  carTwos.push_back(car2);
  car2.setPosition(450,450);
  carTwos.push_back(car2);
  car2.setPosition(800,450);
  carTwos.push_back(car2);

  vector<Sprite> motos;
  moto.setPosition(150,400);
  motos.push_back(moto);
  moto.setPosition(700,400);
  motos.push_back(moto);

  vector<Sprite> trucks;
  truck.setPosition(200,350);
  trucks.push_back(truck);
  truck.setPosition(650,350);
  trucks.push_back(truck);
  truck.setPosition(850,350);
  trucks.push_back(truck);

  vector< vector<Sprite> > floaties;
  floaties.push_back(small_logs);
  floaties.push_back(medium_logs);
  floaties.push_back(large_logs);
  floaties.push_back(med_lilly);
  floaties.push_back(small_lilly);

  vector< vector<Sprite> > traffic;
  traffic.push_back(trucks);
  traffic.push_back(motos);
  traffic.push_back(carTwos);
  traffic.push_back(carOnes);
  traffic.push_back(trailers);

  vector<Sprite> lives;
  frog.setPosition(0,650);
  lives.push_back(frog);
  frog.setPosition(50,650);
  lives.push_back(frog);
  frog.setPosition(100,650);
  lives.push_back(frog);

  vector<Sprite> safe_frogs;
  time_.setPosition(570,650);
  vector<Sprite> thyme;
  load_time(thyme, bar, time_);




  frog.setPosition(Frogger.xpos, Frogger.ypos);
  background.setPosition(0,0);
  gameOver.setPosition((background.getGlobalBounds().width - gameOver.getGlobalBounds().width)/2, (background.getGlobalBounds().height - gameOver.getGlobalBounds().height)/2);
  Clock clock;

  window.setKeyRepeatEnabled(false);
  while (window.isOpen())
  {
    Event Event;
    // Determines what key is pressed and adjusts the frogs position accordingly.
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

      int deltaX = 0;
      bool safe = false;

      //Drawing logs and lillypads
      for(int i =0; i < floaties.size(); ++i)
      {
        for(int k =0; k < floaties[i].size(); ++k)
        {
          window.draw(floaties[i][k]);

          if(i == 0)
          {
            floaties[i][k].move(1,0);
            if(floaties[i][k].getPosition().x >= 950) floaties[i][k].setPosition(-100,200);
            deltaX = 1;
          }
          if(i == 1)
          {
            floaties[i][k].move(2,0);
            if(floaties[i][k].getPosition().x >= 950)floaties[i][k].setPosition(-150,50);
            deltaX = 2;
          }
          if(i == 2)
          {
            floaties[i][k].move(3,0);
            if(floaties[i][k].getPosition().x >= 950) floaties[i][k].setPosition(-250,150);
            deltaX = 3;
          }
          if(i == 3)
          {
            floaties[i][k].move(-2,0);
            if(floaties[i][k].getPosition().x <= -150) floaties[i][k].setPosition(1100,250);
            deltaX = -2;
          }
          if(i == 4)
          {
            floaties[i][k].move(-1,0);
            if(floaties[i][k].getPosition().x <= -100) floaties[i][k].setPosition(1050,100);
            deltaX = -1;
          }
          if(floaties[i][k].getGlobalBounds().intersects(frog.getGlobalBounds()))
          {
            safe = true;
            Frogger.xpos += deltaX;
          }
        }
      }


      int ypos = frog.getPosition().y;
      int xpos = frog.getPosition().x;

      // Checks to see if the frog has found its home and if so it
      if(ypos <= 0)
      {
        if(abs((xpos % 100)- 50) <= 10)
        {

          safe = true;
          xpos = int(xpos / 100)*100 + 50;
          for(int i = 0; i < safe_frogs.size(); ++i)
          {
            if(xpos == safe_frogs[i].getPosition().x) safe = false;
          }
          if(safe)
          {
            frog.setPosition(xpos, 0);
            safe_frogs.push_back(frog);
            reset_frog(Frogger);
          }


        }
      }

      // If the frog falls in the water subtract one life and reset postition
      if(ypos < 300 && safe == false)
      {
        lives.erase(lives.begin()+ lives.size()-1);
        reset_frog(Frogger);
        load_time(thyme, bar, time_);
        clock.restart();

      }
      safe = false;

      // Player can't move off the screen
      if(xpos > 900) Frogger.xpos = 900;
      if(xpos < 0) Frogger.xpos = 0;
      if(ypos > 600) Frogger.ypos = 600;


      //Drawing the traffic
      for(int i = 0; i < traffic.size(); ++i)
      {
        for(int k =0; k < traffic[i].size(); ++k)
        {
          window.draw(traffic[i][k]);
          if(traffic[i][k].getGlobalBounds().intersects(frog.getGlobalBounds()))
          {
            lives.erase(lives.begin()+ lives.size()-1);
            reset_frog(Frogger);
            load_time(thyme, bar, time_);
            clock.restart();

          }

          if(i == 0) //Trucks
          {
            traffic[i][k].move(-3,0);
            if(traffic[i][k].getPosition().x <= 0) traffic[i][k].setPosition(1050,350);
          }
          if(i == 1) //Motos
          {
            traffic[i][k].move(3,0);
            if(traffic[i][k].getPosition().x >= 950) traffic[i][k].setPosition(-50,400);
          }
          if(i == 2) //CarTwos
          {
            traffic[i][k].move(1,0);
            if(traffic[i][k].getPosition().x >= 950) traffic[i][k].setPosition(-50,500);
          }
          if(i == 3) //CarOnes
          {
            traffic[i][k].move(-1,0);
            if(traffic[i][k].getPosition().x <= 0) traffic[i][k].setPosition(1000,450);
          }
          if(i == 4) //Trailers
          {
            traffic[i][k].move(-2,0);
            if(traffic[i][k].getPosition().x <= 0) traffic[i][k].setPosition(1050,550);
          }
        }
      }

      // If there are no lives left then game over.
      if(lives.size() < 1)
      {
        window.draw(gameOver);
        window.display();
        cout << "Game Over" << endl;
        clock.restart();
        while(clock.getElapsedTime().asSeconds() < 5)
        {
        }
        return 0;

      }

      // Drawing lives
      for(int i = 0; i < lives.size(); ++i)
      {
        window.draw(lives[i]);
      }

      // Drawing all the frogs that have found their homes.
      for(int i = 0; i < safe_frogs.size(); ++i)
      {
        window.draw(safe_frogs[i]);
      }

      // Drawing the remaining time.
      for(int i = 0; i < thyme.size(); ++i)
      {
        window.draw(thyme[i]);
      }

      if(clock.getElapsedTime().asSeconds() > 1)
      {

        thyme.erase(thyme.begin()+1);
        if(thyme.size() <= 1)
        {
          lives.erase(lives.begin()+lives.size()-1);
          load_time(thyme, bar, time_);
          clock.restart();
          reset_frog(Frogger);
        }

        clock.restart();
      }

      window.draw(frog);
      window.display();

    }
  return 0;
}
