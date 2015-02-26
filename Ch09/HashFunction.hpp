#ifndef HASH_FUNCTION_HPP
#define HASH_FUNCTION_HPP


int hashCode(const char* p, int len) {
  unsigned int h = 0;
  for (int i = 0; i < len; i++) {
    h = (h << 5) | (h >> 27);
    h += (unsigned int) p[i];
  }
  return int(h);
}

template <typename T>
unsigned int hashCode(const T& x) { // hash the T
  int len = sizeof(x);
  const char* p = reinterpret_cast<const char*>(&x);
  return (unsigned int)hashCode(p, len);
}

#endif
