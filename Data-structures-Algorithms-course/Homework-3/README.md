# Homework 3

Един хубав ден на великия програмист бай Гойко му се наложило да се занимава с тежка административна дейност – да извежда статистика въз основа на големите списъци на катеричките в двора на ФМИ. Статистиката се изразявала в това, да се провери в даден интервал от подредените имена на катеричките колко започват с даден префикс. Понеже бай Гойко е много зает да храни катеричките и да събира обратна връзка за условията им за живот той ви моли да напишете програма за автоматизиране на статистическия процес. Тя трябва да обработва следните заявки:

ENTER < a > < b > - Влизаме в нов интервал на статистиките [a, b]. Интервалите са базирани на 0

QUERY < str > - Пита се колко имена в интервала, който разглеждате в момента, започват с префикса str.

## Входни данни:

На първия ред на стандартния вход ще е изписано едно цяло число Т – броя тестови примери, които ще трябва да реши програмата ви. Всеки тестов пример започва с 2 цели числа N (не повече от 1000000) и Q (не повече от 500000), съответно броя низове и броя заявки (от гореописаните), с които ще трябва да се справите. Приемете, че първоначално сте в интервала [0, N-1]. Следват N на брой низа съставени от малки латински букви с дължина не повече от 8 символа - последователността от имена – не непременно сортирана. След това има Q на брой заявки от споменатите по-горе. Вие трябва да сортирате имената преди да започнете да обработвате заявките. Не трябва да използвате сортировка от стандартната библиотека. Сортирането трябва да е стабилно!

## Изход:

За всяка заявка от вида QUERY трябва да изведете на нов ред, броя низове с търсеното качество.

## Примерен вход
```
2
5 5
ivan mitko joro peshe tobi
ENTER 0 1
QUERY jor
ENTER 3 4
QUERY t
QUERY j
4 2
eli mama pesho maq
QUERY ma
QUERY elica
```

## Примерен изход
```
1
1
0
2
0
```