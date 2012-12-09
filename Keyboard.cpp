/**
 *
 * KNOW BUGS/QUIRKS:
 * - Qt does not appear to differentiate between shift, control, windows key, and alt
 *   on the left and right side of the keyboard.  Both sides return the same Qt::Key value.
 */

#include "Keyboard.h"
#include <QApplication>
#include <iostream>

/**
 * Constructor
 */
//Keyboard::Keyboard() {
  
//}

/**
 * Draws the keyboard to the screen
 */
void Keyboard::draw() {
  int w = 38; // Standard key width
  int h = 40; // Standard key height
  int s = 5; // Spacing between keys

  // Row 1
  Key *accent = new Key("~\n`", Qt::Key_QuoteLeft, Qt::Key_AsciiTilde, this);
  accent->resize(w,h);
  accent->move(0,0);
  accent->show();
  keys[0] = accent;
  Key *one = new Key("!\n1", Qt::Key_1, Qt::Key_Exclam, this);
  one->resize(w,h);
  one->move((w+s),0);
  one->show();
  keys[1] = one;
  Key *two = new Key("@\n2", Qt::Key_2, Qt::Key_At, this);
  two->resize(w,h);
  two->move(2*(w+s),0);
  two->show();
  keys[2] = two;
  Key *three = new Key("#\n3", Qt::Key_3, Qt::Key_NumberSign, this);
  three->resize(w,h);
  three->move(3*(w+s),0);
  three->show();
  keys[3] = three;
  Key *four = new Key("$\n4", Qt::Key_4, Qt::Key_Dollar, this);
  four->resize(w,h);
  four->move(4*(w+s),0);
  four->show();
  keys[4] = four;
  Key *five = new Key("%\n5", Qt::Key_5, Qt::Key_Percent, this);
  five->resize(w,h);
  five->move(5*(w+s),0);
  five->show();
  keys[5] = five;
  Key *six = new Key("^\n6", Qt::Key_6, Qt::Key_AsciiCircum, this);
  six->resize(w,h);
  six->move(6*(w+s),0);
  six->show();
  keys[6] = six;
  Key *seven = new Key("&&\n7", Qt::Key_7, Qt::Key_Ampersand, this);
  seven->resize(w,h);
  seven->move(7*(w+s),0);
  seven->show();
  keys[7] = seven;
  Key *eight = new Key("*\n8", Qt::Key_8, Qt::Key_Asterisk, this);
  eight->resize(w,h);
  eight->move(8*(w+s),0);
  eight->show();
  keys[8] = eight;
  Key *nine = new Key("(\n9", Qt::Key_9, Qt::Key_ParenLeft, this);
  nine->resize(w,h);
  nine->move(9*(w+s),0);
  nine->show();
  keys[9] = nine;
  Key *zero = new Key(")\n0", Qt::Key_0, Qt::Key_ParenRight, this);
  zero->resize(w,h);
  zero->move(10*(w+s),0);
  zero->show();
  keys[10] = zero;
  Key *leftBracket = new Key("{\n[", Qt::Key_BracketLeft, Qt::Key_BraceLeft, this);
  leftBracket->resize(w,h);
  leftBracket->move(11*(w+s),0);
  leftBracket->show();
  keys[11] = leftBracket;
  Key *rightBracket = new Key("}\n]", Qt::Key_BracketRight, Qt::Key_BraceRight, this);
  rightBracket->resize(w,h);
  rightBracket->move(12*(w+s),0);
  rightBracket->show();
  keys[12] = rightBracket;
  Key *backspace = new Key("Backspace", Qt::Key_Backspace, 0, this);
  backspace->resize(2.5*w,h);
  backspace->move(13*(w+s),0);
  backspace->show();
  keys[13] = backspace;

  // Row 2
  Key *tab = new Key("Tab", Qt::Key_Tab, 0, this);
  tab->resize(1.5*w,h);
  tab->move(0,h+s);
  tab->show();
  keys[14] = tab;
  Key *apostrophe = new Key("\"\n'", Qt::Key_Apostrophe, Qt::Key_QuoteDbl, this);
  apostrophe->resize(w,h);
  apostrophe->move(w+s+(.5*w),h+s);
  apostrophe->show();
  keys[15] = apostrophe;
  Key *comma = new Key("<\n,", Qt::Key_Comma, Qt::Key_Less, this);
  comma->resize(w,h);
  comma->move(2*(w+s)+(.5*w),h+s);
  comma->show();
  keys[16] = comma;
  Key *period = new Key(">\n.", Qt::Key_Period, Qt::Key_Greater, this);
  period->resize(w,h);
  period->move(3*(w+s)+(.5*w),h+s);
  period->show();
  keys[17] = period;
  Key *p = new Key("P", Qt::Key_P, 0, this);
  p->resize(w,h);
  p->move(4*(w+s)+(.5*w),h+s);
  p->show();
  keys[18] = p;
  Key *y = new Key("Y", Qt::Key_Y, 0, this);
  y->resize(w,h);
  y->move(5*(w+s)+(.5*w),h+s);
  y->show();
  keys[19] = y;
  Key *f = new Key("F", Qt::Key_F, 0, this);
  f->resize(w,h);
  f->move(6*(w+s)+(.5*w),h+s);
  f->show();
  keys[20] = f;
  Key *g = new Key("G", Qt::Key_G, 0, this);
  g->resize(w,h);
  g->move(7*(w+s)+(.5*w),h+s);
  g->show();
  keys[21] = g;
  Key *c = new Key("C", Qt::Key_C, 0, this);
  c->resize(w,h);
  c->move(8*(w+s)+(.5*w),h+s);
  c->show();
  keys[22] = c;
  Key *r = new Key("R", Qt::Key_R, 0, this);
  r->resize(w,h);
  r->move(9*(w+s)+(.5*w),h+s);
  r->show();
  keys[23] = r;
  Key *l = new Key("L", Qt::Key_L, 0, this);
  l->resize(w,h);
  l->move(10*(w+s)+(.5*w),h+s);
  l->show();
  keys[24] = l;
  Key *forwardSlash = new Key("?\n/", Qt::Key_Slash, Qt::Key_Question, this);
  forwardSlash->resize(w,h);
  forwardSlash->move(11*(w+s)+(.5*w),h+s);
  forwardSlash->show();
  keys[25] = forwardSlash;
  Key *equals = new Key("+\n=", Qt::Key_Equal, Qt::Key_Plus, this);
  equals->resize(w,h);
  equals->move(12*(w+s)+(.5*w),h+s);
  equals->show();
  keys[26] = equals;
  Key *backslash = new Key("|\n\\", Qt::Key_Backslash, Qt::Key_Bar, this);
  backslash->resize(2*w,h);
  backslash->move(13*(w+s)+(.5*w),h+s);
  backslash->show();
  keys[27] = backslash;

  // Row 3
  Key *capsLock = new Key("Caps Lock", Qt::Key_CapsLock, 0, this);
  capsLock->resize(2*w,h);
  capsLock->move(0,2*(h+s));
  capsLock->show();
  keys[28] = capsLock;
  Key *a = new Key("A", Qt::Key_A, 0, this);
  a->resize(w,h);
  a->move(w+s+w,2*(h+s));
  a->show();
  keys[29] = a;
  Key *o = new Key("O", Qt::Key_O, 0, this);
  o->resize(w,h);
  o->move(2*(w+s)+w,2*(h+s));
  o->show();
  keys[30] = o;
  Key *e = new Key("E", Qt::Key_E, 0, this);
  e->resize(w,h);
  e->move(3*(w+s)+w,2*(h+s));
  e->show();
  keys[31] = e;
  Key *u = new Key("U", Qt::Key_U, 0, this);
  u->resize(w,h);
  u->move(4*(w+s)+w,2*(h+s));
  u->show();
  keys[32] = u;
  Key *i = new Key("I", Qt::Key_I, 0, this);
  i->resize(w,h);
  i->move(5*(w+s)+w,2*(h+s));
  i->show();
  keys[33] = i;
  Key *d = new Key("D", Qt::Key_D, 0, this);
  d->resize(w,h);
  d->move(6*(w+s)+w,2*(h+s));
  d->show();
  keys[34] = d;
  Key *kH = new Key("H", Qt::Key_H, 0, this);
  kH->resize(w,h);
  kH->move(7*(w+s)+w,2*(h+s));
  kH->show();
  keys[35] = kH;
  Key *t = new Key("T", Qt::Key_T, 0, this);
  t->resize(w,h);
  t->move(8*(w+s)+w,2*(h+s));
  t->show();
  keys[36] = t;
  Key *n = new Key("N", Qt::Key_N, 0, this);
  n->resize(w,h);
  n->move(9*(w+s)+w,2*(h+s));
  n->show();
  keys[37] = n;
  Key *kS = new Key("S", Qt::Key_S, 0, this);
  kS->resize(w,h);
  kS->move(10*(w+s)+w,2*(h+s));
  kS->show();
  keys[38] = kS;
  Key *hyphen = new Key("_\n-", Qt::Key_Minus, Qt::Key_Underscore, this);
  hyphen->resize(w,h);
  hyphen->move(11*(w+s)+w,2*(h+s));
  hyphen->show();
  keys[39] = hyphen;
  Key *enter = new Key("Enter", Qt::Key_Enter, 0, this);
  enter->resize(100,h); // 100px = 2.63w
  enter->move(12*(w+s)+w,2*(h+s));
  enter->show();
  keys[40] = enter;

  // Row 4
  Key *leftShift = new Key("Shift", Qt::Key_Shift, 0, this);
  leftShift->resize((2.5*w),h);
  leftShift->move(0,3*(h+s));
  leftShift->show();
  keys[41] = leftShift;
  Key *semicolon = new Key(":\n;", Qt::Key_Semicolon, Qt::Key_Colon, this);
  semicolon->resize(w,h);
  semicolon->move(w+s+(1.5*w),3*(h+s));
  semicolon->show();
  keys[42] = semicolon;
  Key *q = new Key("Q", Qt::Key_Q, 0, this);
  q->resize(w,h);
  q->move(2*(w+s)+(1.5*w),3*(h+s));
  q->show();
  keys[43] = q;
  Key *j = new Key("J", Qt::Key_J, 0, this);
  j->resize(w,h);
  j->move(3*(w+s)+(1.5*w),3*(h+s));
  j->show();
  keys[44] = j;
  Key *k = new Key("K", Qt::Key_K, 0, this);
  k->resize(w,h);
  k->move(4*(w+s)+(1.5*w),3*(h+s));
  k->show();
  keys[45] = k;
  Key *x = new Key("X", Qt::Key_X, 0, this);
  x->resize(w,h);
  x->move(5*(w+s)+(1.5*w),3*(h+s));
  x->show();
  keys[46] = x;
  Key *b = new Key("B", Qt::Key_B, 0, this);
  b->resize(w,h);
  b->move(6*(w+s)+(1.5*w),3*(h+s));
  b->show();
  keys[47] = b;
  Key *m = new Key("M", Qt::Key_M, 0, this);
  m->resize(w,h);
  m->move(7*(w+s)+(1.5*w),3*(h+s));
  m->show();
  keys[48] = m;
  Key *kW = new Key("W", Qt::Key_W, 0, this);
  kW->resize(w,h);
  kW->move(8*(w+s)+(1.5*w),3*(h+s));
  kW->show();
  keys[49] = kW;
  Key *v = new Key("V", Qt::Key_V, 0, this);
  v->resize(w,h);
  v->move(9*(w+s)+(1.5*w),3*(h+s));
  v->show();
  keys[50] = v;
  Key *z = new Key("Z", Qt::Key_Z, 0, this);
  z->resize(w,h);
  z->move(10*(w+s)+(1.5*w),3*(h+s));
  z->show();
  keys[51] = z;
  Key *rightShift = new Key("Shift", Qt::Key_Shift, 0, this);
  rightShift->resize(124,h); // 124px = 3.263w
  rightShift->move(11*(w+s)+(1.5*w),3*(h+s));
  rightShift->show();
  keys[52] = rightShift;

  // Row 5
  Key *leftControl = new Key("Ctrl", Qt::Key_Control, 0, this);
  leftControl->resize((2*w),h);
  leftControl->move(0,4*(h+s));
  leftControl->show();
  keys[53] = leftControl;
  Key *leftWin = new Key("Win\nKey", Qt::Key_Meta, 0, this);
  leftWin->resize(w,h);
  leftWin->move(w+s+w,4*(h+s));
  leftWin->show();
  keys[54] = leftWin;
  Key *leftAlt = new Key("Alt", Qt::Key_Alt, 0, this);
  leftAlt->resize((2*w),h);
  leftAlt->move(2*(w+s)+w,4*(h+s));
  leftAlt->show();
  keys[55] = leftAlt;
  Key *spaceBar = new Key("Space", Qt::Key_Space, 0, this);
  spaceBar->resize(201,h); //201px = 5.29w
  spaceBar->move(3*(w+s)+(2*w),4*(h+s));
  spaceBar->show();
  keys[56] = spaceBar;
  Key *rightAlt = new Key("Alt", Qt::Key_Alt, 0, this);
  rightAlt->resize((2*w),h);
  rightAlt->move(4*(w+s)+(2*w)+163,4*(h+s));
  rightAlt->show();
  keys[57] = rightAlt;
  Key *rightWin = new Key("Win\nKey", Qt::Key_Meta, 0, this);
  rightWin->resize(w,h);
  rightWin->move(5*(w+s)+(3*w)+163,4*(h+s));
  rightWin->show();
  keys[58] = rightWin;
  Key *menu = new Key("Menu", Qt::Key_Menu, 0, this);
  menu->resize(w,h);
  menu->move(6*(w+s)+(3*w)+163,4*(h+s));
  menu->show();
  keys[59] = menu;
  Key *rightControl = new Key("Ctrl", Qt::Key_Control, 0, this);
  rightControl->resize((2*w),h);
  rightControl->move(7*(w+s)+(3*w)+163,4*(h+s));
  rightControl->show();
  keys[60] = rightControl;

  // Loop through all of the keys and set their focus policy to 'no focus'
  for(int i = 0; i < 61; i++) {
    keys[i]->setFocusPolicy(Qt::NoFocus);
  }
}

void Keyboard::keyPressEvent(QKeyEvent *e) {
  cout << "Key code: " << e->key() << endl;
  toggleKey(e->key(), true);
}

void Keyboard::keyReleaseEvent(QKeyEvent *e) {
  cout << "Key code: " << e->key() << endl;
  toggleKey(e->key(), false);
}

void Keyboard::toggleKey(const int keyCode, bool press) {
  // Loop through all 61 keys are check if the keycode belongs to 
  // one of them.  Press that key.

  for(int i = 0; i < 61; i++) {
    if(keys[i]->primaryKeyCode == keyCode || keys[i]->secondaryKeyCode == keyCode) {
      keys[i]->setDown(press);
      keys[i]->setDefault(false);

      update();
      repaint();

      return;
    }
  }
}
  
/*
int main(int argcount, char **argv) {
  
  QApplication app(argcount, argv);
  Keyboard keyboard;

  keyboard.draw();
  keyboard.show();

  return app.exec();
  
}
*/
