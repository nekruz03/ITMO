import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

public class CoffeeMachine {

    public static class Output {
        private String descr;

        public Output(String descr) {
            this.descr = descr;
        }

        public String getDescr() {
            return descr;
        }
    }

    public static class Input {
        private String descr;

        public Input(String descr) {
            this.descr = descr;
        }

        public String getDescr() {
            return descr;
        }
    }

    public static class State {
        private String descr;
        private Map<Input, Transition> transitions = new HashMap<>();

        public State(String descr) {
            this.descr = descr;
        }

        public String getDescr() {
            return descr;
        }

        public void addTransition(Input input, State nextState, Output output) {
            transitions.put(input, new Transition(nextState, output));
        }

        public Transition getTransition(Input input) {
            return transitions.get(input);
        }
    }

    public static class Transition {
        private State nextState;
        private Output output;

        public Transition(State nextState, Output output) {
            this.nextState = nextState;
            this.output = output;
        }

        public State getNextState() {
            return nextState;
        }

        public Output getOutput() {
            return output;
        }
    }

    private State currentState;

    public CoffeeMachine(State initialState) {
        this.currentState = initialState;
    }

    public State getCurrentState() {
        return currentState;
    }

    public Output transition(Input input) {
        Transition transition = currentState.getTransition(input);
        if (transition != null) {
            currentState = transition.getNextState();
            return transition.getOutput();
        }
        return null;
    }

    public static void main(String[] args) throws IOException {
        State idle = new State("Ожидание");
        State brewing = new State("Приготовление кофе");
        State dispensing = new State("Выдача кофе");
        State idleWithoutCup = new State("Ожидание (без чашки)");

        Input insertCup = new Input("Вставить чашку");
        Input removeCup = new Input("Убрать чашку");
        Input startBrewing = new Input("Начать приготовление");
        Input brewingComplete = new Input("Приготовление завершено");
        Input startDispensing = new Input("Начать выдачу");
        Input dispensingComplete = new Input("Выдача завершена");

        Output startBrewingOutput = new Output("Начало приготовления кофе");
        Output startDispensingOutput = new Output("Начало выдачи кофе");
        Output coffeeReadyOutput = new Output("Кофе готов");
        Output noCupOutput = new Output("Не обнаружена чашка");

        idle.addTransition(insertCup, brewing, startBrewingOutput);
        idle.addTransition(startDispensing, dispensing, startDispensingOutput);
        idle.addTransition(startBrewing, brewing, startBrewingOutput);
        idle.addTransition(removeCup, idleWithoutCup, noCupOutput);

        brewing.addTransition(brewingComplete, dispensing, coffeeReadyOutput);
        brewing.addTransition(removeCup, idleWithoutCup, noCupOutput);

        dispensing.addTransition(dispensingComplete, idle, null);
        dispensing.addTransition(removeCup, idleWithoutCup, noCupOutput);

        idleWithoutCup.addTransition(insertCup, idle, null);

        CoffeeMachine coffeeMachine = new CoffeeMachine(idle);

        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        System.out.println("Добро пожаловать в симулятор кофейной машины!");

        String input;

        while (true) {
            System.out.println("Доступные действия: Вставить чашку, Убрать чашку, Начать приготовление, Приготовление завершено, Начать выдачу, Выдача завершена, Выход");
            System.out.print("Введите ваше действие: ");
            input = reader.readLine().trim().toLowerCase();
            Output machineOutput = null;

            switch (input) {
                case "вставить чашку":
                    machineOutput = coffeeMachine.transition(insertCup);
                    break;
                case "убрать чашку":
                    machineOutput = coffeeMachine.transition(removeCup);
                    break;
                case "начать приготовление":
                    machineOutput = coffeeMachine.transition(startBrewing);
                    break;
                case "приготовление завершено":
                    machineOutput = coffeeMachine.transition(brewingComplete);
                    break;
                case "начать выдачу":
                    machineOutput = coffeeMachine.transition(startDispensing);
                    break;
                case "выдача завершена":
                    machineOutput = coffeeMachine.transition(dispensingComplete);
                    break;
                case "выход":
                    System.out.println("Завершение работы симулятора кофейной машины.");
                    reader.close();
                    return;
                default:
                    System.out.println("Некорректное действие. Пожалуйста, попробуйте снова.");
            }

            if (machineOutput != null) {
                System.out.println("Действие машины: " + machineOutput.getDescr());
            }

            System.out.println("Новое состояние: " + coffeeMachine.getCurrentState().getDescr());
        }
    }
}
