#include <iostream>
#include "rack.h"
#include "tile.h"
#include "bag.h"
#include "square.h"
#include "board.h"
#include "game.h"
#include "play.h"
#include "player.h"
#include "utils.h"

using namespace std;

void testTile();
void testBag();
void testRack();
void testSquare();
void testBoard();
void testGame();
void testPlay();

int main()
{
	testGame();
	return 0;
}

void testTile()
{
	enum_location l1 = BAG;
	Tile t('a', 1, l1);
	t.show();
}

void testBag()
{
	Bag b;
	b.show();
	vector<Tile*> t = b.draw(200);
	cout << "\n";
	b.show();
}

void testRack()
{
	enum_location l1 = RACK;
	vector<Tile*> t;

	for(int i = 0; i < 3; i++) {
		t.push_back(new Tile('A', 1, l1));
	}

	Rack r;
	r.fill(t);
	r.show();
	try {
		cout << boolalpha;
		cout << r.isEmpty();
		// t.clear();
		// t = r.getTileStrVec("ABA");
		// r.show();
		// for(Tile* x : t)
		//     cout << x->getLetterStr();
	}
	catch(string e) {
		BOLD_RED(e);
		cout << endl;
	}
}

void testSquare()
{
	enum_sqType type = N;
	Square s(type, 4, 5);
	s.show();
}

void testBoard()
{
	Bag bag;
	Board b;
	vector<Tile*> t;
	Rack r;

	for(int i = 0; i < 3; i++) {
		t.push_back(new Tile('A', 1, RACK));
	}
	b.placeTile(t.back(), 7, 7);
	b.show();
	r.show();
	Tile* temp = b.retrieve(7, 7);
	r.addTile(temp);
	b.show();
	temp->show();
	r.show();

}

void testGame()
{
	Game g;
	g.run();
}

void testPlay()
{
	Player* testPlayer = new Player("Kodus");
	Play p(testPlayer);
	Board b;
	enum_location l1 = RACK;
	vector<Tile*> t;
	vector<Tile*> tilesInStr;

	t.push_back(new Tile('A', 1, l1));
	t.push_back(new Tile('B', 2, l1));
	t.push_back(new Tile('C', 1, l1));
	t.push_back(new Tile('D', 1, l1));
	t.push_back(new Tile('E', 1, l1));

	b.placeTile(t[1], 8, 7);
	b.placeTile(t[2], 9, 7);
	b.placeTile(t[3], 10, 7);
	b.placeTile(t[4], 11, 7);

	b.placeTile(t[4], 11, 8);

	b.placeTile(t[0], 7, 7);
	b.placeTile(t[1], 7, 8);
	b.placeTile(t[2], 7, 9);
	b.placeTile(t[3], 7, 10);
	b.placeTile(t[4], 7, 11);

	b.placeTile(t[0], 8, 9);
	tilesInStr.push_back(t[0]);
	b.placeTile(t[1], 9, 9);
	tilesInStr.push_back(t[1]);
	b.placeTile(t[2], 10, 9);
	tilesInStr.push_back(t[2]);
	b.placeTile(t[3], 11, 9);
	tilesInStr.push_back(t[3]);

	b.show();

	try {
		for(vector<Tile*> t : p.getWords(tilesInStr, &b, 8, 9, 'v')) {
			for(Tile* ti : t) {
				ti->show();
				ti->getSquare()->show();
				cout << "\n";
			}
			cout << endl;
		}

		// for(int i = 7; i < 12; i++) {
		//     conn = p.getConnectedTiles(b.getSquare(7, i)->getTile(), 'h');
		//     for(Tile* t : conn) {
		//         t->show();
		//         cout << ", ";
		//     }
		//     cout << endl;
		// }
	}
	catch(string str) {
		BOLD_RED(str);
		cout << "\n";
	}
}
