class Foo {
    private int counter;
    
    public Foo() {
        this.counter=1;
    }

    public void first(Runnable printFirst) throws InterruptedException {
        synchronized(this){
            while(counter!=1) wait();
            counter+=1;
            // printFirst.run() outputs "first". Do not change or remove this line.
            printFirst.run();
            notifyAll();
        }
    }

    public void second(Runnable printSecond) throws InterruptedException {
        synchronized(this){
            while(counter!=2) wait();
            counter+=1;
            // printSecond.run() outputs "second". Do not change or remove this line.
            printSecond.run();
            notifyAll();
        }
    }

    public void third(Runnable printThird) throws InterruptedException {
        synchronized(this){
            while(counter!=3) wait();
            counter+=1;
            // printThird.run() outputs "third". Do not change or remove this line.
            printThird.run();
            notifyAll();
        }
    }
}