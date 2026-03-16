# מטלה אחת-עשרה - אלגוריתמי STL

## יושרה אקדמית

במהלך העבודה על המטלות, מותר להתייעץ עם סטודנטים אחרים ולחפש מידע באינטרנט. עם זאת, חל איסור להעתיק קטעי קוד שלמים ממקורות חיצוניים, כולל סטודנטים אחרים, אתרי אינטרנט ומודלי בינה מלאכותית (כגון ChatGPT).

יש לדווח על כל עזרה שקיבלתם, בין אם מדובר בהתייעצות עם סטודנטים אחרים או במידע שנמצא באינטרנט, בהתאם ל[תקנון היושר של המחלקה](https://www.ariel.ac.il/wp/cs/wp-content/uploads/sites/88/2020/08/Guidelines-for-Academic-Integrity.pdf).
**במקרה של שימוש בכלי בינה מלאכותית (AI), יש לצרף את הפרומפטים שהוזנו ואת התשובות שהתקבלו**.


## הקדמה
מטלה זו היא חלק מהקורס "C++ תכנות מתקדם" ומטרתה להדגים שימוש ב**אלגוריתמי STL** בשפת C++. המטלה מתמקדת ביישום כלי לניתוח טקסטים ועיבוד נתונים תוך שימוש באלגוריתמים מ-`<algorithm>` ו-`<numeric>`, איטרטורי IO, אלגוריתמי סטים, פרמוטציות, ועוד.

## מבנה המטלה
במטלה זו תתבקשו לממש מספר קבצי `.cpp` על בסיס קבצי ה-`.hpp` שסופקו. המטלה מדגימה:
- **for_each, transform** - מעבר והמרה על מכולות
- **queries** - `find`, `find_if`, `count`, `count_if`, `all_of`, `any_of`, `none_of`, `accumulate`
- **movers** - `copy`, `copy_if`, `move`, `replace`, `replace_if`, `fill`, `generate`
- **value modifiers** - `sort`, `partial_sort`, `nth_element`, `stable_sort`
- **structure changers** - `remove`, `remove_if`, `unique`, `reverse`, `rotate`, `partition`, `stable_partition`
- **set algorithms** - `set_union`, `set_intersection`, `set_difference`, `set_symmetric_difference`, `merge`, `includes`
- **permutations** - `next_permutation`, `prev_permutation`
- **insert/erase idiom** - `erase-remove idiom`
- **IO iterators** - `istream_iterator`, `ostream_iterator`
- **שימוש בנושאים ממטלות קודמות** - מכולות STL, תבניות, מרחבי שמות

## דרישות והנחיות
- להשלים את הקוד החסר בקבצים שסופקו
- לוודא שהקוד מתקמפל ופועל ללא שגיאות
- **חובה** להשתמש באלגוריתמי STL מהספרייה `<algorithm>` ו-`<numeric>`
- לעבור בהצלחה את הטסטים הכתובים בקובץ test.cpp

## תכונות C++ שיש להדגים
1. **for_each / transform** - החלת פונקציה על כל איברי מכולה
2. **שאילתות (Queries)** - `find`, `find_if`, `count_if`, `all_of`, `any_of`, `none_of`
3. **מעתיקים ומזיזים (Movers)** - `copy`, `copy_if`, `replace`, `fill`, `generate`
4. **משנה ערכים (Value Modifiers)** - `sort`, `stable_sort`, `partial_sort`, `nth_element`
5. **משנה מבנה (Structure Changers)** - `remove_if`, `unique`, `reverse`, `rotate`, `partition`
6. **אלגוריתמי סטים (Set Algorithms)** - `set_union`, `set_intersection`, `set_difference`
7. **פרמוטציות (Permutations)** - `next_permutation`, `prev_permutation`
8. **erase-remove idiom** - מחיקה מותנית ממכולה
9. **IO Iterators** - `ostream_iterator`, `istream_iterator`
10. **`<numeric>`** - `accumulate`, `inner_product`, `partial_sum`, `iota`

## קבצים במטלה

### קבצים שסופקו:
- **DataProcessor.hpp** - מחלקה לעיבוד נתונים מספריים עם אלגוריתמי STL
- **TextAnalyzer.hpp** - מחלקה לניתוח טקסטים עם אלגוריתמי STL
- **SetOperations.hpp** - פונקציות לפעולות סטים עם אלגוריתמי STL
- **AlgorithmShowcase.hpp** - פונקציות חופשיות המדגימות קטגוריות אלגוריתמים
- **main.cpp** - תוכנית ראשית המדגימה שימוש בכל הפונקציות עם הערות המציינות את הפלט הצפוי
- **test.cpp** - קובץ בדיקות
- **doctest.h** - ספרייה לביצוע בדיקות אוטומטיות
- **Makefile** - קובץ לקימפול והרצה אוטומטית של הפרויקט

### קבצים שעליכם ליצור ולממש:
- **DataProcessor.cpp** - מימוש עיבוד הנתונים
- **TextAnalyzer.cpp** - מימוש ניתוח הטקסטים
- **SetOperations.cpp** - מימוש פעולות הסטים
- **AlgorithmShowcase.cpp** - מימוש פונקציות המדגימות אלגוריתמים

## הוראות קימפול והרצה

### שימוש ב-Makefile:
הפרויקט כולל `Makefile` שמאפשר קימפול והרצה בקלות:

```bash
make        # מקמפל ומריץ את התוכנית הראשית
make test   # מקמפל ומריץ את בדיקות היחידה
make clean  # מנקה את כל קבצי הקימפול
```


## טיפים להשלמת המטלה
- קראו היטב את הוראות המטלה והבינו את הדרישות
- **אלגוריתמי STL לא משנים את גודל המכולה** — `remove`/`remove_if` מחזירים איטרטור לסוף החדש, ויש להשתמש ב-`erase` כדי למחוק בפועל
- **אלגוריתמי סטים דורשים מכולות ממוינות** — וודאו שהקלט ממוין לפני שימוש ב-`set_union` וכו'
- `ostream_iterator` מאפשר להדפיס מכולה בקלות עם `copy` — **שימו לב** שה-delimiter מתווסף אחרי כל איבר, כולל האחרון
- `back_inserter` מאפשר להוסיף תוצאות לסוף וקטור
- `iota` ממלא מכולה בערכים עולים
- `accumulate` מחשב סכום (או צבירה כללית)
- **פורמט `toString`**: מספרים שלמים (כגון 5.0) צריכים להופיע ללא נקודה עשרונית (כלומר "5" ולא "5.000000")
- **פרמוטציות**: כדי לקבל את כל הפרמוטציות עם `next_permutation`, יש לוודא שהוקטור ממוין בסדר עולה לפני תחילת הלולאה
- **שם הפונקציה `includes`**: שימו לב שפונקציה זו עלולה להתנגש עם `std::includes` — וודאו שאתם משתמשים ב-namespace הנכון
- בדקו את התוכנית עם מקרי קצה ותנאים שונים
- הקפידו על כתיבת קוד נקי, קריא ומתועד היטב

## הגשה
יש להגיש את כל הקבצים המלאים (עם הקוד המושלם). וודאו שהקוד מתקמפל ורץ כראוי לפני ההגשה.

---

בהצלחה!