enum Month {
    jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

class Date {
    public:
        class Invalid{};

        Date(int y, Month m, int d);

        int year();
        Month month();
        int day();

        void add_day(int n);
        void add_month(int n);
        void add_year(int n);
    private:
        int y,d;
        Month m;
        bool is_valid();
};
