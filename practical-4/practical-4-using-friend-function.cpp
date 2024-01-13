#include<iostream>
using namespace std;

class Distance2;

class Distance1
{
    private:
        float miles;

    public:
        Distance1(float m = 0) : miles(m) {}

        friend Distance1 add_dist(Distance1 d1, Distance2 d2);
        friend Distance2 add_dist_K(Distance1 d1, Distance2 d2);

        void display()
        {
            cout <<"Distance in miles: "<< miles <<" miles"<< endl;
        }
};

class Distance2
{
    private:
        int kmeters;
        int meters;

    public:
        Distance2(int km = 0, int m = 0) : kmeters(km), meters(m) {}
        friend Distance1 add_dist(Distance1 d1, Distance2 d2);
        friend Distance2 add_dist_K(Distance1 d1, Distance2 d2);

        void display()
        {
            cout <<"Distance in kmeters: "<< kmeters <<" km and "<< meters <<" meters"<< endl;
        }
};

Distance1 add_dist(Distance1 d1, Distance2 d2)
{
    float km1 = d1.miles * 1.60934;
    float totalKm = km1 + d2.kmeters + (static_cast<float>(d2.meters) / 1000);
    float totalMiles = totalKm / 1.60934;

    return Distance1(totalMiles);
}
Distance2 add_dist_K(Distance1 d1, Distance2 d2)
{
    float km1 = d1.miles * 1.60934;
    float totalKm = km1 + d2.kmeters + (static_cast<float>(d2.meters) / 1000);
    int Km = static_cast<int>(totalKm);
    int Meters = static_cast<int>((totalKm - Km) * 1000);

    return Distance2(Km, Meters);
}

int main()
{
    float miles, kmeters, meters;
    cout <<"Enter distance in miles: ";
    cin >> miles;
    cout <<"Enter distance in kilometers: ";
    cin >> kmeters;
    cout <<"Enter distance in meters: ";
    cin >> meters;
    Distance1 dist1(miles);
    Distance2 dist2(kmeters, meters);

    Distance1 result1 = add_dist(dist1, dist2);
    result1.display();

    Distance2 result2 = add_dist_K(dist1, dist2);
    result2.display();

    return 0;
}
