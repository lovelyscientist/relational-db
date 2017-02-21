# Завдання

Оскільки наша програма є таск-менеджером, то головною задачею є управління завданнями, зміна їх статусу та контроль роботи працівників

## Створення нової задачі

Нижче можна побачити форму створення нового завдання. Для того натиснути кнопку "Додати" - необхідно правильно заповнити усі поля.

![Завдання](/screens/s18.tiff)

###### Назва завдання

Елемент: Поле для вводу  
Тип поля: Текстовий  
Заповнення: Обов'язкове  


###### Публікація для якої виконується завдання

Елемент: Випадаючий список  
Дані списку: Публікації системи  
Тип поля: Текстовий  
Заповнення: Обов'язкове  

###### Тип завдання

Елемент: Випадаючий список   
Дані списку: {Іллюстрація, Редакція, Переклад}  
Тип поля: Текстовий  
Заповнення: Обов'язкове  
 
###### Скільки часу займе завдання

Елемент: Поле для вводу  
Тип поля: Ціле число
Заповнення: Обов'язкове   
Мінімальне значення: 1  
Максимальне значення: 100  

###### Працівник що буде виконувати завдання

Елемент: Випадаючий список  
Дані списку: {Список усіх працівників видавництва}  
Тип поля: Текстовий  
Заповнення: Обов'язкове  

###### Описання завдання

Елемент: Поле для вводу збільшеного розміру  
Тип поля: Текстовий  
Заповнення: Не обов'язкове  

## Перегляд повної інформації про завдання

В цьому розділі можна переглянути список усіх завдань користувачів.
Присутні так поля:

* Ідентифікаційний код задачі
* Назва
* Статус
* Працівник, що виконує
* Скільки часу залишилось
* Скільки часу було заплановано
* Працівник, що виконує роботу
* Опис завдання

![Інформація про завдання](/screens/s9.tiff)

Дане представлення даних дозволяє сортувати дані за будь-якою з колонок.

###### Що необхідно щоб знайти відкрити повну інформацію про завдання?

Для того, щоб знайти повну інформацію про завдання є 2 способи дій:
1) перейти на сторінку панелі задач та натиснути на зменшену версію задачі  
2) в пошуковому полі браузера ввести адресу як ідентифікаційний код завдання

## Зміна статусу задачі

Для того, щоб змінити статус задачі необхідно натиснути на ту кнопку, яка назвою співпадає з новим статусом задачі.

На рисунку нижче можна побачити розташування кнопок статусів

![Інформація про завдання](/screens/s9.tiff)

######  Статус To-Do 

Якщо задача знаходиться в такому статусі - то це означає, що її потрібно виконати і вона ще не була почата 

######  Статус In progress

Такий статус мають задачі, які зараз виконуються працівником. Один працівник може мати декілька задач у цьому статусі одночасно.

######  Статус Done

Задачі з таким статусом вже виконані, але в разі певної ситуації можуть бути перевідкриті з новим статусом.

## Логування витраченого часу на задачу

Для того, щоб менеджер міг знати скільки часу було витрачено сьогодні працівником або скільки часу було витрачено на задачу - існує можливість логувати час до завдання.

![Інформація про завдання](/screens/s12.tiff)
Так виглядає вікно логування.

######  Витрачений час на задачу 

Елемент: Поле для вводу  
Тип поля: Ціле число
Заповнення: Обов'язкове   
Мінімальне значення: 1  
Максимальне значення: 5

Можна побачити, що якщо це поле не заповнене - то час не можна залогувати і з'являється червоне повідомлення, як на малюнку нижче

![Інформація про завдання](/screens/s13.tiff)

## Перегляд списку усіх завдань

Можна переглянути список усіх завдань користувачів системи.
Підтримує можливість сортування та перегляду конкретної сторінки, якщо записів у таблиці більше 5.

![Інформація про завдання](/screens/s22.tiff)