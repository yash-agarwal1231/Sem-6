class MessagerThread implements Runnable {
    public void run() {
        for (int i = 1; i <= 5; i++) {
            System.out.println("Hello from Runnable Thread");
        }
    }

    public static void main(String[] args) {
        MessageThread obj = new MessageThread();
        Thread t = new Thread(obj);
        t.start();
    }
}
