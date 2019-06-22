#define DEBUG 1
/**
 * File    : D2.cpp
 * Author  : Kazune Takahashi
 * Created : 6/23/2019, 5:37:29 AM
 * Powered by Visual Studio Code
 */

#include <iostream>
#include <memory>
#include <algorithm>

template <typename T, typename A = std::allocator<T>>
struct vector_base
{ // vector のためのメモリ構造
  A alloc;
  T *elem;  // 先頭
  T *space; // 拡張用領域の先頭
  T *last;  // 終端

  vector_base(const A &a, typename A::size_type n = 0, typename A::size_type m = 0)
      : alloc{a}, elem{alloc.allocate(n + m)}, space{elem + n}, last{elem + n + m} {}

  ~vector_base() { alloc.deallocate(elem, last - elem); }

  vector_base(const vector_base &) = delete;            // コピー演算は行えない
  vector_base &operator=(const vector_base &) = delete; // コピー代入演算子も無効化

  vector_base(vector_base &&);            // ムーブ演算を行う
  vector_base &operator=(vector_base &&); // ムーブ代入演算子
};

template <typename T, typename A = std::allocator<T>>
class vector
{
private:
  vector_base<T, A> vb;
  void destroy_elements();

public:
  using size_type = typename A::size_type; // vector 要素用の型
  explicit vector(size_type n = 0, const T &val = T(), const A &a = A());

  ~vector() { destroy_elements(); };

  vector(const vector &a);            // コピーコンストラクタ
  vector &operator=(const vector &a); // コピー代入演算子

  vector(vector &&a);            // ムーブコンストラクタ
  vector &operator=(vector &&a); // ムーブ代入演算子

  size_type size() const { return vb.space - vb.elem; }
  size_type capacity() const { return vb.last - vb.elem; }
  void reserve(size_type n);                // 容量を n まで増やす
  void resize(size_type n, const T & = {}); // 要素数を n に変更
  void clear() { resize(0); }
  void push_back(const T &);

  T *begin() { return vb.elem; }
  T *end() { return vb.space; }
  const T &operator[](const size_type t) const { return *(vb.elem + t); }
  T &operator[](const size_type t) { return *(vb.elem + t); }
};

template <typename T, typename A>
vector_base<T, A>::vector_base(vector_base &&a)
    : alloc{a.alloc}, elem{a.elem}, space{a.space}, last{a.last}
{
  a.elem = a.space = a.last = nullptr;
}

template <typename T, typename A>
vector_base<T, A> &vector_base<T, A>::operator=(vector_base &&a)
{
  swap(*this, a);
  return *this;
}

template <typename T, typename A>
void vector<T, A>::destroy_elements()
{
  for (T *p = vb.elem; p != vb.space; ++p)
  {
    p->~T();
  }
  vb.space = vb.elem;
}

template <typename T, typename A>
vector<T, A>::vector(size_type n, const T &val, const A &a) : vb{a, n}
{
  std::uninitialized_fill(vb.elem, vb.elem + n, val);
}

template <typename T, typename A>
vector<T, A>::vector(const vector &a) : vb{a.vb.alloc, a.size()}
{
  std::uninitialized_copy(a.begin(), a.end(), vb.elem);
}

template <typename T, typename A>
vector<T, A> &vector<T, A>::operator=(const vector &a)
{
  vector temp{a};
  swap(*this, temp);
  return *this;
}

template <typename T, typename A>
vector<T, A>::vector(vector &&a) : vb{std::move(a.vb)} {}

template <typename T, typename A>
vector<T, A> &vector<T, A>::operator=(vector &&a)
{
  swap(vb, a.vb);
  return *this;
}

/*
template <typename C>
using Value_type = typename C::value_type;

template <typename In, typename Out>
Out uninitialized_move(In b, In e, Out oo)
{
  using T = Value_type<Out>;
  for (; b != e; ++b, ++oo)
  {
    new (static_cast<void *>(&*oo)) T{std::move(*b)};
    b->~T();
  }
  return oo;
}
*/

template <typename T, typename A>
void vector<T, A>::reserve(size_type new_alloc)
{
  if (new_alloc <= capacity())
  {
    return;
  }
  vector_base<T, A> b{vb.alloc, new_alloc - size()};
  // uninitialized_move(vb.elem, vb.elem + size(), b.elem);
  T *oo = b.elem;
  for (auto begin = vb.elem; begin != vb.elem + size(); ++begin, ++oo)
  {
    new (static_cast<void *>(&*oo)) T{std::move(*begin)};
    begin->~T();
  }
  swap(vb, b);
}

/*
template <typename In>
void destroy(In b, In e)
{
  for (; b != e; ++b)
  {
    b->~Value_type<In>();
  }
}
*/

template <typename T, typename A>
void vector<T, A>::resize(size_type new_size, const T &val)
{
  reserve(new_size);
  if (size() < new_size)
  {
    std::uninitialized_fill(vb.elem + size(), vb.elem + new_size, val);
  }
  else
  {
    auto b = vb.elem + new_size;
    auto e = vb.elem + size();
    for (; b != e; ++b)
    {
      b->~T();
    }
  }
  vb.space = vb.elem + new_size;
}

template <typename T, typename A>
void vector<T, A>::push_back(const T &val)
{
  if (capacity() == size())
  {
    reserve(size() ? 2 * size() : 8);
  }
  vb.alloc.construct(&vb.elem[size()], val);
  ++vb.space;
}

typedef long long ll;

int N;
typedef std::pair<ll, ll> work;
vector<work> V;

int main()
{
  std::cin >> N;
  for (auto i = 0; i < N; i++)
  {
    ll a, b;
    std::cin >> a >> b;
    V.push_back(work(b, a));
  }
  std::sort(V.begin(), V.end());
  ll now = 0;
  for (auto i = 0; i < N; i++)
  {
    now += V[i].first;
    if (now > V[i].second)
    {
      std::cout << "No" << std::endl;
      return 0;
    }
  }
  std::cout << "Yes" << std::endl;
}