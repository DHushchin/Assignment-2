# Assignment-2

## Варіант #1
Ваше завдання: визначити список країн-переможців у конкурсі Допобачення-2020. На вхід подається назва директорії, всередині якої необхідно зчитати всі текстові файли .csv. Всі [файли](examples_2/var1/eurovision1.csv) ([посилання на папку на гітхабі](https://github.com/ProgramEngineeringKPI/Introduction-To-Programming/blob/master/labs_spring_2020/examples_2/var1)) мають такий формат `Країна, кількість голосів за у країні №1-№20`, наприклад:
```csv
1
Ukraine,78000,6156,495,7,9456460,45645,21213,898...
```
Перший рядок містить кількість країн, що знаходяться в кожному з файлів.
Кожен наступний рядок містить кількість голосів від кожної з країн-учасниць. У прикладі вище Україна отримала 78000 голосів від країни №1, 6156 голосів від країни №2 тощо. Країна, що набрала найбільшу кількість голосів (в стовпчику) отримує 12 балів, друге місце – 10, з третього по десяте – 8-1 бал відповідно. Необхідно порахувати сумарну кількість балів за кожну країну і вивести топ-10 переможців у текстовий файл.

#### Вхідні та вихідні дані
На вхід програми подається назва теки. Вивід – файл results.csv з результатами найкращих десяти країн Допобачення-2020.
Вихідні дані повинні містити єдиний результат виконання для всіх файлів вхідної директорії.
