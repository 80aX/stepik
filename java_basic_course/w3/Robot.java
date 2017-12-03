// На игровом поле находится робот. Позиция робота на поле описывается двумя целочисленным 
// координатами: X и Y. Ось X смотрит слева направо, ось Y — снизу вверх. (Помните, как рисовали 
// графики функций в школе?)

// В начальный момент робот находится в некоторой позиции на поле. Также известно, куда робот 
// смотрит: вверх, вниз, направо или налево. Ваша задача — привести робота в заданную точку
// игрового поля.


public class Robot {
    
    public int X = 0;
    public int Y = 0;  
    public Direction robotDir = Direction.DOWN;
    
    public Robot(int X, int Y, Direction robotDir) {
        this.X = X;
        this.Y = Y;
        this.robotDir = robotDir;
    }
    
    public Direction getDirection() {
        // направление движения робота
        return robotDir;
    }
    
    public enum Direction {
        UP,
        DOWN,
        LEFT,
        RIGHT
    }

    public int getX() {
        // текущая координата X
        return X;
    }

    public int getY() {
        // текущая координата Y
        return Y;
    }

    public void turnLeft() {
        // повернуться на 90 градусов против часовой стрелки
        System.out.println("Turning left...");
        if (robotDir == Direction.UP) {
            this.robotDir = Direction.LEFT;
            return;
        } else if (robotDir == Direction.DOWN) {
            this.robotDir = Direction.RIGHT;
            return;
        } else if (robotDir == Direction.LEFT) {
            this.robotDir = Direction.DOWN;
            return;
        } else if (robotDir == Direction.RIGHT) {
            this.robotDir = Direction.UP;
            return;
        }
    }

    public void turnRight() {
        // повернуться на 90 градусов по часовой стрелке
        System.out.println("Turning right...");
        if (robotDir == Direction.UP) {
            this.robotDir = Direction.RIGHT;
            return;
        } else if (robotDir == Direction.DOWN) {
            this.robotDir = Direction.LEFT;
            return;
        } else if (robotDir == Direction.LEFT) {
            this.robotDir = Direction.UP;
            return;
        } else if (robotDir == Direction.RIGHT) {
            this.robotDir = Direction.DOWN;
            return;
        }
    }

    public void stepForward() {
        // шаг в направлении взгляда
        // за один шаг робот изменяет одну свою координату на единицу
        if (robotDir == Direction.UP) {
            this.Y += 1;
            System.out.println("UP, Y = " + getY());
            return;
        } else if (robotDir == Direction.DOWN) {
            this.Y -= 1;
            System.out.println("DOWN, Y = " + getY());
            return;
        } else if (robotDir == Direction.LEFT) {
            this.X -= 1;
            System.out.println("LEFT X = " + getX());
            return;
        } else if (robotDir == Direction.RIGHT) {
            this.X += 1;
            System.out.println("RIGHT X = " + getX());
            return;
        }
    }

    public static void moveRobot(Robot robot, int toX, int toY) {
        if (toX > robot.getX()) {
            while (robot.getDirection() != Direction.RIGHT) {
                robot.turnRight();
            }
            while (toX != robot.getX()) {
                robot.stepForward();
            }
        } else if (toX < robot.getX()) {
            while (robot.getDirection() != Direction.LEFT) {
                robot.turnLeft();
            }
            while (toX != robot.getX()) {
                robot.stepForward();
            }
        }
        if (toY > robot.getY()) {
            while (robot.getDirection() != Direction.UP) {
                robot.turnRight();
            }
            while (toY != robot.getY()) {
                robot.stepForward();
            }
        } else if (toY < robot.getY()) {
            while (robot.getDirection() != Direction.DOWN) {
                robot.turnLeft();
            }
            while (toY != robot.getY()) {
                robot.stepForward();
            }
        }
    }


    public static void main(String[] args) {
        Robot Android = new Robot(0, 0, Direction.UP);
        System.out.println("Start X = " + Android.getX());
        System.out.println("Start Y = " + Android.getY());
        System.out.println("Start Direction: " + Android.getDirection());
        moveRobot(Android, 11, 8);
        System.out.println("Final X = " + Android.getX());
        System.out.println("Final Y = " + Android.getY());
        System.out.println("Final Direction: " + Android.getDirection());
    }
}
