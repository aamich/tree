// problem in interview with Mercedez-Benz
// 9/23/2019
// 
// implement the template Vector3 and Matrix3, so as to perform 
// Vector3+Vector3
// cout << Vector3
// Matrix3*Vector3
//
// for float.

#include <iostream>
#include <vector>
#include <ostream>

using namespace std;

template<class T>
class Vector3 {
    public:
        Vector3(): _v{0,0,0} {}
        Vector3(T a, T b, T c) {
            _v.push_back(a);
            _v.push_back(b);
            _v.push_back(c);
        }
        ~Vector3(){}
        friend Vector3<T> operator+(const Vector3<T>& v1, const Vector3<T>& v2) {
            return Vector3<T>(v1._v[0]+v2._v[0], v1._v[1]+v2._v[1], v1._v[2]+v2._v[2]); 
        }
        friend T operator*(const Vector3<T>& v1, const Vector3<T>& v2) {
            return v1._v[0]*v2._v[0]+v1._v[1]*v2._v[1]+v1._v[2]*v2._v[2]; 
        }
        //    friend T dotProduct(const Vector3<T>& v1, const Vector3<T>& v2) {
        //        return v1._v[0]*v2._v[0]+v1._v[1]*v2._v[1]+v1._v[2]*v2._v[2]; 
        //    }
        friend ostream& operator<<(ostream& co, const Vector3<T>& data) {
            co << data._v[0] << " " << data._v[1] << " " << data._v[2] << endl;
        }

    private:
        vector<T> _v;
};

template <class T>
class Matrix3 {
    public:
        Matrix3(): _m{Vector3<T>(), Vector3<T>(), Vector3<T>()}{}
        Matrix3(const Vector3<T>& v1, const Vector3<T>& v2, const Vector3<T>& v3) {
            _m.push_back(v1);
            _m.push_back(v2);
            _m.push_back(v3);
        }
        const Vector3<T>& operator[](int i) const {
            return _m[i];
        }
        friend Vector3<T> operator*(const Matrix3<T>& m, const Vector3<T>& v) {
            //return Vector3<T>(dotProduct(m[0],v), dotProduct(m[1],v), dotProduct(m[2],v));
            return Vector3<T>(m[0]*v, m[1]*v, m[2]*v);
        }
        friend ostream& operator<<(ostream& co, const Matrix3<T>& data) {
            co << data[0];
            co << data[1];
            co << data[2];
        }
    private:
        vector<Vector3<T>> _m;
};

int main() {
    Vector3<float> v0;
    Vector3<float> v1(1,2,3);
    Vector3<float> v2(1,2,4);
    cout << "v0="<< v0;
    cout << "v1="<< v1;
    cout << "v2="<< v2;
    Vector3<float> v3 = v0+v1;
    cout << "v3=" << v3;
    cout << "v3+v2=" << v3+v2;
    cout << "v3*v2=" << v3*v2 << endl;
    Matrix3<float> m1;
    Matrix3<float> m2(Vector3<float>(1,2,3), Vector3<float>(4,5,6), Vector3<float>(7,8,9));
    cout << "m1=" << endl; cout << m1;
    cout << "m2=" << endl; cout << m2;
    cout << "m2*v1=" << endl; cout << m2*v1;
}
