#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <iomanip>

using namespace std;

class Track
{
    public: 

    string name;
    tm creationdate;
    int duration;

};

class Audiopleer
{  
   private:   
   vector <Track> tracks;
   bool isplaying = 0;
   
    
   public:
   void addtrack (string* name, tm* creationdate, int* duration)
   {
     Track track;
     track.name = *name;
     track.creationdate = *creationdate;
     track.duration = *duration;
     tracks.push_back(track);
   }

   void play(string* name)
   {
     if(isplaying)
     {
        cout << "track already started" << endl;
        return;
     }

     for(int i = 0; i < tracks.size(); i ++)
     {
        if(*name == tracks[i].name)
        {
           isplaying = true;
           cout << "name: " << tracks[i].name << " created date " << tracks[i].creationdate.tm_hour << ":" <<
           tracks[i].creationdate.tm_min << " duration " << tracks[i].duration << endl;
           return;
        }
     }

       cout << "track not found" << endl;
   }

   void pause()
   {
     if(!isplaying)
     {
      cout << "no track is currently plating" << endl;
      return;
     }

      cout << "track paused" << endl;
      isplaying = false;
   }

   void next()
   {
     if(tracks.empty())
     {
      cout << "no track avaliable" << endl;
      return;
     }

     int randomindex =rand() % tracks.size();
     isplaying = true;
     cout << "name: " << tracks[randomindex].name << " created date " << tracks[randomindex].creationdate.tm_hour << ":" <<
      tracks[randomindex].creationdate.tm_min << " duration " << tracks[randomindex].duration << endl;
   }

   void stop()
   {
     if(!isplaying)
     {
      cout << "no track is currently playing" << endl;
      return;
     }

     cout << "track stoped" << endl;
     isplaying = false;
   }

   
};

int main()
{
  Audiopleer pleer; 

 string name = "track1"; 
 int duration = 150;  
 time_t t = time(NULL);
 tm local = *localtime(&t);
 get_time(&local, "%H:%M");
 local.tm_hour = 18;
 local.tm_min = 35;
 pleer.addtrack(&name, &local, &duration);

  name = "track2"; 
  duration = 180;  
 time_t a = time(NULL);
 tm local2 = *localtime(&a);
 get_time(&local2, "%H:%M");
 local2.tm_hour = 19;
 local2.tm_min = 40;
 pleer.addtrack(&name, &local2, &duration);

  name = "track3"; 
  duration = 200;  
 time_t b = time(NULL);
 tm local3 = *localtime(&b);
 get_time(&local3, "%H:%M");
 local3.tm_hour = 20;
 local3.tm_min = 50;
 pleer.addtrack(&name, &local3, &duration);

 while(1)
 {
    string command;
    cout << "enter command: play, next, pause, stop, exit: ";
    cin >> command;

    if(command == "play")
    {
      string name;
      cout << "enter name track:";
      cin >> name;
      pleer.play(&name);
    }

    else if(command == "pause")
    {
      pleer.pause();
    }

    else if(command == "next")
    {
      pleer.next();
    }

    else if(command == "stop")
    {
      pleer.stop();
    }

    else if(command == "exit")
    {
      cout << "exit from programm" << endl;
      break;
    }

    else
    {
      cout << "invalid command" << endl;
    }
    
 }




 return 0;
}