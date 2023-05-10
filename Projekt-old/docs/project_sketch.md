# Project sketch

## Topic: "calendar with event handling"

## UI Proposal

### Month layout
```
           March 2023
    Sun Mon Tue Wed Thu Fri Sat
 9 | 26  27  28   1   2   3   4
10 |  5   6   7   8   9  10  11
11 | 12  13  14  15  16  17  18
12 | 19  20  21  22  23  24  25
13 | 26  27  28  29  30  31   1
14 |  2   3   4   5   6   7   8
```
Current day has marked background.
All events have marked background to a user-defined color.

### Week layout
```
Week 10 - March 2023
Sun  5 | 
Mon  6 | meeting
Tue  7 | 
Wed  8 | lectures
Thu  9 | exam
Fri 10 | 
Sat 11 | 
```
### Day layout
```
Thursday March 9 2023
...
 6 AM | 
 7 AM | 
 8 AM | : exam :
 9 AM | :      :
10 AM | :      :
11 AM | :      :
12 AM | :......:
...
```
### Schedule layout
```
Sun Mar  5 | no events for today
Sun Mar  6 | 9:30 - 11:30   exam
Sun Mar  8 | 8:30 - 10:00   lectures
Sun Mar  9 | 8:00 - 12:00   exam
Sun May 16 | All day        birthday
```

### Zarządzanie wydarzeniami
Jako interfejs zarządzania proponuję prosty kreator pozwalający wpisać nazwę wydarzenia, datę i godzinę kiedy występuje, koloru oraz dodatkowe noty.

```
Name: _________________
Starts: __/__/____ __:__
Ends: __/__/____ __:__
Color: #______
Notes: _______________________________

[Save] [Cancel]
```
Podobny układ pojawi się w przypadku edycji i podglądu (jedynie zmienią się dostępne przyciski u dołu układu).

## Keybinds

 - `→` - next day
 - `←` - previous day
 - `↑` - next week
 - `↓` - previous week
 - `a` - month view
 - `w` - week view
 - `d` - day view
 - `s` - schedule view
 - `c` - create a new event
 - `e` - edit selected event
 - `x` - delete selected event
 - `Enter` - show details 
 - `Backspace` - go back
 - `q` - quit
