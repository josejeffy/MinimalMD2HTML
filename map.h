#include <string.h>
typedef struct {
  char *key;
  char *value;
} map;

char *get_value(map *pairs, char *key, int len) {
  for (int i = 0; i < len; i++) {
    if (strcmp(key, pairs[i].key) == 0) {
      return pairs[i].value;
    }
  }
  return NULL;
}
