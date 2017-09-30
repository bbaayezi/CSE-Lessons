package lab4.person;


public class Main {

    public static void main(String[] args) {
        Person[] personArr = new Person[5];
        String[] nameArr = {"Allan", "Bob", "Cathy", "David", "ed"};
        String[] addressArr = {"London", "Liverpool", "Des Moines", "Montana", "Cleveland"};
        int[] ageArr = {17, 19, 20, 21, 19};
        for (int i = 0; i < 5; i++) {
            personArr[i] = new Person(nameArr[i], ageArr[i], addressArr[i]);
            System.out.println(personArr[i].toString() + "\n*************************************\n");
        }
    }
}
