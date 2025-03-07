# <strong> <span style="color:blue"> Лабораторная 1.

**Задание**

Синтез управляющего конечного автоматаТребуется спроектировать конечный автомат, управляющий стиральной машиной.

Стиральная машина работает в трех режимах: залив, стирка, слив. Машина начинает работать по нажатию кнопки «Пуск».
После этого происходит залив воды до тех пор, пока датчик d1 уровня воды не подаст сигнал о заполнения бака стиральной машины. Затем происходит стирка.
Эта операция ограничивается с помощью таймера t.
Если таймер исправен, то по истечении определенного времени он выдает сигнал о завершении стирки и стиральная машина переходит в режим слива воды. Если таймер неисправен, то стиральная машина переходит в состояние «дефект», т.е. в состояние ожидания, которое может быть прервано только после ремонта стиральной машины.
Из состояния «дефект» стиральная машина не может возвратиться в исходное состояние, поэтому последующее нажатие кнопки «Пуск» не приведет к запуску стиральной машины.
Из неисправного состояния после ремонта стиральная машина возвращается в исходное состояние по сигналу reset. Слив воды завершается при получении сигнала от датчика d2 уровня воды о том, что в баке воды нет. После этого стиральная машина возвращается в исходное состояние.

Содержание отчета:
Описание задания
Описание реализации конечного автомата
Диаграммы переходов
Выводы

Другие интересные библиотеки:
https://github.com/alysivji/finite-state-machine

# <strong> <span style="color:blue"> Лабораторная 2.

**Задание**

Методы принятия решений в сложных системах

С помощью метода анализа иерархий осуществить многокритериальный выбор для любой задачи на свое усмотрение (выбор фильма для просмотра, выбор ресторана для посещения, выбор телефона для покупки и т.п.).
Количество возможных альтернатив и критериев для выбора не менее 4-5.

Полезные материалы:
https://edu.tltsu.ru/sites/sites_content/site216/html/media67140/lec1_is-2_2020%20(1).pdf

# <strong> <span style="color:blue"> Лабораторная 3.


**Задание**

Построение и исследование нечетких систем


Цель работы: получить навыки построения нечетких систем.

Используя Python-библиотеку Skfuzzy построить нечёткую базу знаний для моделирования нечеткой системы в соответствии с выбранным вариантом.

Этапы выполнения работы:
1. Определить входные и выходные лингвистические переменные (общее
количество лингвистических переменных должно быть не менее 3).
2. Задать функции принадлежности для нечетких подмножеств, определенных на
значениях выбранных лингвистических переменных (не менее трех значений
для каждой лингвистической переменной).
3. Определить нечеткие правила, описывающие работу рассматриваемой системы (не менее четырех правил, при этом 
нечёткая база знаний должна быть полной).
4. Промоделировать работу нечеткой системы (не менее 5 прогонов с разными входными данными, заданными случайным образом).

Содержание отчета:
1. Описание предметной области, в том числе описание входных данных и выходных переменных, в чем они измеряются и т.д.
2. Нечеткие правила, описывающие работу системы.
3. Графики функций принадлежности для нечетких подмножеств, определенных на значениях выбранных лингвистических переменных.
4. Результаты нечёткого вывода (не мене пяти прогонов).

# <strong> <span style="color:blue"> Лабораторная 4.

**Задание**

Марковские цепи

Для выполнение лабораторной работы необходимо выполнить следующие пункты:
1. Придумать эргодическую марковскую цепь, содержащую не менее 4-х состояний.
2. Нарисовать диаграмму переходов и записать матрицу переходных вероятностей данной цепи.
3. Промоделировать марковскую цепь пошагово с несколькими различными начальными
векторами вероятностей состояний и получить конечные вектора, к которым привело моделирование.
4. Построить графики изменения компонентов финальных векторов, а также графики изменения среднеквадратического отклонения на каждом шаге моделирования для всех начальных векторов.
5. Найти стационарное распределение аналитически (см. пример в презентации).
6. Сравнить вектора из пункта 3 и вектор, рассчитанный аналитически, между собой.

Замечания:
1. При пошаговом моделировании необязательно хранить все значения стационарного вектора, можно иметь два вектора вероятностей – старый и новый, главное, после применения формулы переписать значение из нового в старое и далее можно совершить еще один шаг моделирования (вычислить новый вектор). Вычисления продолжаются до тех пор, пока среднеквадратичное отклонение между старым и новым вектором не будет меньше заданного значения  ошибки e.
2. Для нахождения аналитического решения вектора стационарного распределения можно использовать функцию numpy.linalg.solve.

# <strong> <span style="color:blue"> Лабораторная 5.


**Задание**


Оценка параметров математической модели

1. По заданному дифференциальному уравнению второго порядка (см. Варианты задания) построить систему дифференциальных уравнений первого порядка в форме Коши (см. Преобразование математических моделей динамической системы).
2. Осуществить оценку параметров системы дифференциальных уравнений, описывающих заданную систему, при единичном входном воздействии  и нулевых начальных условиях x(0) = 0 (см. Оценка параметров ДУ).

Содержание отчета:
1. Дифференциальное уравнение второго порядка
2. Система дифференциальных уравнений первого порядка
3. Графики результатов оценки параметров
4. Исходный код функций

# <strong> <span style="color:blue"> Лабораторная 6.


**Задание**


Исследование систем управления

Задание выполняется с использованием библиотеки
Control Systems Library (python-control).


1. По заданному дифференциальному уравнению второго порядка (см. варианты задания для лабораторной работы "Оценка параметров математической модели") перейти к описанию в пространстве состояний и в виде передаточной функции.
2. Исследовать динамические и частотные характеристики объекта управления: оценить устойчивость, управляемость и наблюдаемость, построить переходную и импульсную характеристику, диаграмму Боде, фазовый портрет.
3. Перейти к дискретному описанию системы при шаге дискретизации T = 0.1 с.
4. Оценить устойчивость дискретной системы, построить график переходного процесса.
