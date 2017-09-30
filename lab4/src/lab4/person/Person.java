package lab4.person;

public class Person {
    String name;
    int age;
    String address;
    public Person (String name, int age, String address) {
        this.name = name;
        this.age = age;
        this.address = address;
    }

    public String getName() {
        return name;
    }

    @Override
    public String toString() {
        return "Person name: " + name + "\nPerson age: " + age + "\nPerson address: " + address;
    }
}
