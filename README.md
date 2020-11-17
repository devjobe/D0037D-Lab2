# D0037D Lab 2

```yaml
User: ojaebh-0  
Time estimate: 4h
Difficulty rating: easy
Visual Studio version: 2019
```

## Usage

All the tasks are contained in a single executable selectable through a menu according to task 7.

## Reflection

> What did you learn? What did you know already?

I learned that it's very easy to introduce buffer overflow errors with `cin` and char arrays if you
naivly use the streaming operator `>>`. Either use for example `setw` or `.get` to avoid it.

I also learned that `int**` doesn't implicitly convert to `const int**` but to `const int* const*`.

> What was difficult in the lab? How did you overcome it?

No unreasonable difficulties.

> How can the lab be improved?

I think maybe point out that no dynamic allocation is needed (besides standard library things) 
at the beginning of the lab description.

> Additionally, write an estimate how many hours you spent on this lab.

Kinda forgot to keep track but very rough estimate is 4h.