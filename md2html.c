#include "map.h"
#include <stdio.h>
#define LEN 200
#define OUTPUTLEN 2000

int main(int argc, char **argv) {
  map html_tags[] = {{"#", "<h1>%s</h1>"},
                     {"##", "<h2>%s</h2>"},
                     {">", "<blockquote>%s</blockquote>"},
                     {"p", "<p>%s</p>"},
                     {"!", "<img src='%s'/>"}};
  int len = sizeof(html_tags) / sizeof(map), i, j;
  char md[LEN], html[OUTPUTLEN] = "<html><head><link rel=\"stylesheet\" href=\"https://cdn.jsdelivr.net/npm/water.css@2/out/water.css\"></head></body>", temp[LEN];
  FILE *mdfile = fopen(argv[1], "r");
  if (mdfile == NULL)
    return -1;
  while (1) {
    if (feof(mdfile))
      break;
    fgets(md, LEN - 1, mdfile);
    if (strcmp(md, "") != 0) {
      char buf[3];
      j = 0, i = 0;
      while (md[i] != ' ') {
        buf[j++] = md[i++];
      }
      buf[j] = '\0';
      char *pattern = get_value(html_tags, buf, len);
      if (pattern == NULL) {
        sprintf(temp, get_value(html_tags, "p", len), md);
      } else {
        sprintf(temp, get_value(html_tags, buf, len), &md[++i]);
      }
      strcat(html, temp);
    }
  }
  strcat(html, "</body></html>");
  printf("%s\n", html);
  fclose(mdfile);
  return 0;
}
