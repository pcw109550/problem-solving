#include <bits/stdc++.h>
using namespace std;

string ColorList = "wyrogb";
string DirList   = "UDFBLR";
string RotList   = "+-";
enum Color { w, y, r, o, g, b };
enum Dir   { U, D, F, B, L, R };
enum Rot   { CW, CCW };
struct Method {
    Dir dir;
    Rot rot;
};
typedef Color Faces[6][3][3];

/*
 *             B
 *           L U R D
 *             F
 * 
 *            9 8 7
 *            6 5 4
 *            3 2 1            
 * 
 *     7 4 1  1 2 3  3 6 9  1 2 3
 *     8 5 2  4 5 6  2 5 8  4 5 6
 *     9 6 3  7 8 9  1 4 7  7 8 9
 * 
 *            1 2 3
 *            4 5 6
 *            7 8 9
*/

class Cube {
    public:
        Cube();
        void printFace(Dir dir);
        void printFaces(void);
        void rotate(Method method);
        void rotateHelper(Rot rot, Color &a, Color &b, Color &c, Color &d);
        void rotateFace(Method method);
        void rotateSide(Method method);
    private:
        Faces faces;
};

Cube::Cube() {
    for (int idx = 0; idx < 6; idx++) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                faces[idx][i][j] = static_cast<Color>(idx);
            }
        }
    }
}

void Cube::printFace(Dir dir) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << ColorList[faces[dir][i][j]];
        }
        cout << '\n';
    }
}

void Cube::printFaces(void) {
    for (int i = 0; i < 6; i++) {
        printFace(static_cast<Dir>(i));
        cout << '\n';
    }
}

void Cube::rotate(Method method) {
    rotateFace(method);
    rotateSide(method);
}

void Cube::rotateFace(Method method) {
    Dir dir = method.dir;
    Rot rot = method.rot;
    rotateHelper(rot, faces[dir][0][1], faces[dir][1][0], \
                      faces[dir][2][1], faces[dir][1][2]);
    rotateHelper(rot, faces[dir][0][0], faces[dir][2][0], \
                      faces[dir][2][2], faces[dir][0][2]);
}

void Cube::rotateSide(Method method) {
    Dir dir = method.dir;
    Rot rot = method.rot;
    switch (dir) {
        case U:
            for (int i = 0; i < 3; i++) {
                rotateHelper(rot, faces[B][0][i], faces[L][0][i], \
                                  faces[F][0][i], faces[R][0][i]);
            }
            break;
        case D:
            for (int i = 0; i < 3; i++) {
                rotateHelper(rot, faces[B][2][i], faces[R][2][i], \
                                  faces[F][2][i], faces[L][2][i]);
            }
            break;
        case F:
            for (int i = 0; i < 3; i++) {
                rotateHelper(rot, faces[U][2][i], faces[L][2 - i][2], \
                                  faces[D][2][i], faces[R][i][0]);
            }                            
            break;
        case B:
            for (int i = 0; i < 3; i++) {
                rotateHelper(rot, faces[U][0][i], faces[R][i][2], \
                                  faces[D][0][i], faces[L][2 - i][0]); 
            }    
            break;
        case L:
            for (int i = 0; i < 3; i++) {
                rotateHelper(rot, faces[B][i][2], faces[D][i][2], \
                                  faces[F][2 - i][0], faces[U][2 - i][0]);
            }                   
            break;
        case R:
            for (int i = 0; i < 3; i++) {
                rotateHelper(rot, faces[B][i][0], faces[U][2 - i][2], \
                                  faces[F][2 - i][2], faces[D][i][0]);
            }
            break;
        default:
            assert(false);
            break;
    }
}

void Cube::rotateHelper(Rot rot, Color &a, Color &b, Color &c, Color &d) {
    switch (rot) {
        case CW:
            swap(a, b); swap(b, c); swap(c, d);
            break;
        case CCW:
            swap(d, c); swap(c, b); swap(b, a);
            break;
        default:
            assert(false);
            break;
    }
}

inline void task() {
    int numMethod; string temp;
    cin >> numMethod;
    Method methods[numMethod];
    for (int i = 0; i < numMethod; i++) {
        cin >> temp;
        methods[i].dir = static_cast<Dir>(DirList.find(temp[0]));
        methods[i].rot = static_cast<Rot>(RotList.find(temp[1]));
    }
    Cube cube;
    for (int i = 0; i < numMethod; i++) {
        cube.rotate(methods[i]);
    }
    cube.printFace(U);
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T; cin >> T;
    while (T--) { task(); }
}