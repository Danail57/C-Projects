#include <iostream>
#include <string>

using namespace std;

class MiniWorld
{
	string name;
	int length;
public:
	MiniWorld(string n, int 1) : name(n), length(1){}
	virtual void describe() { cout << "Welcome to " << name << " track! Length: " << length << endl; }
	virtual int get_length() { return length; }
	virtual string get_name() { return name; }
};

class DesertTrack : public MiniWorld
{
public:
	DesertTrack() : MiniWorld("Desert", 100) {}
	void describe() override { cout << "Hot desert track! Watch out for sand patches!" << endl; }
};

class CityTrack : public MiniWorld
{
public:
	CityTrack() : MiniWorld("City", 250) {}
	void describe() override { cout << "Busy city streets! Lots of turns and obstacles!" << endl; }
};

class MountainTrack : public MiniWorld
{
public:
    MountainTrack() : MiniWorld("Mountain", 1200) {}
    void describe() override { cout << "Mountainous terrain! Steep slopes and sharp turns!" << endl; }
};

class CampingTrack : public MiniWorld
{
public:
    CampingTrack() : MiniWorld("Camping", 900) {}
    void describe() override { cout << "Camping area with dirt paths and small rivers!" << endl; }
};

class MineTrack : public MiniWorld
{
public:
    MineTrack() : MiniWorld("Mine", 1100) {}
    void describe() override { cout << "Dark mine tunnels! Careful with tight corners!" << endl; }
};

class ForestTrack : public MiniWorld
{
public:
    ForestTrack() : MiniWorld("Forest", 950) {}
    void describe() override { cout << "Forest track! Trees and obstacles everywhere!" << endl; }
};

class SiloTrack : public MiniWorld
{
public:
    SiloTrack() : MiniWorld("Silo", 850) {}
    void describe() override { cout << "Silo track! Watch for slopes!" << endl; }
};

class RanchTrack : public MiniWorld
{
public:
    RanchTrack() : MiniWorld("Ranch", 1000) {}
    void describe() override { cout << "Ranch track! Mud and open fields!" << endl; }
};

class MilitaryBaseTrack : public MiniWorld
{
public:
    MilitaryBaseTrack() : MiniWorld("Military Base", 1050) {}
    void describe() override { cout << "Military Base! Obstacles and barricades!" << endl; }
};

class FishingVillageTrack : public MiniWorld
{
public:
    FishingVillageTrack() : MiniWorld("Fishing Village", 900) {}
    void describe() override { cout << "Fishing Village! Narrow streets and docks!" << endl; }
};

// ======== Example Usage ========
int main()
{
    MiniWorld* tracks[] = {
        new DesertTrack(),
        new CityTrack(),
        new MountainTrack(),
        new CampingTrack(),
        new MineTrack(),
        new ForestTrack(),
        new SiloTrack(),
        new RanchTrack(),
        new MilitaryBaseTrack(),
        new FishingVillageTrack()
    };

    for (auto track : tracks)
    {
        cout << "Track: " << track->get_name() << endl;
        track->describe();
        cout << "Length: " << track->get_length() << " units\n" << endl;
    }

    // Cleanup
    for (auto track : tracks) delete track;

    return 0;
}
