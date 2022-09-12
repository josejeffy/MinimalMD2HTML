# MinimalMD2HTML
A minimal markdown to html convertor using C

Supports only 5 tags
- #(space)content => h1
- ##(space)content => h2
- >(space)content => blockquote
- !(space)link to image => img (different from usual implementations)
- p is used for any content without any identifiers 

Usage: ./md2html test.md > test.html

**test.md**

``` md
# md 2 html 
> Minimal convertor in C
test continues
```

**test.html**

``` html
<h1>md 2 html 
</h1><blockquote>Minimal convertor in C
</blockquote><p>test continues</p>
```
