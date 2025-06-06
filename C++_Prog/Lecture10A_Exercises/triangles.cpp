
int main()
{
using namespace Graph_lib;
Point tl(100,100);
Simple_window win(tl,600,400,"Canvas");
vector<Triangle*>t_vec; // save the addresses, to delete later
for (int i=0; i<10; i++) {
Triangle *t = new Triangle(150+i*20, 150+i*20);
win.attach( *t ) ;
t_vec.push_back( t ) ;
}
win.wait_for_button();
// Housekeeping at the end
for (int i=0; i<10; i++) delete(t_vec[i]) ;
}