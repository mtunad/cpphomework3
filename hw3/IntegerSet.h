class IntegerSet {
    public:
        IntegerSet();
        void inputSet();
        void unionSet(IntegerSet, IntegerSet &);
        void intersectionSet(IntegerSet, IntegerSet &);
        void printSet() const;

    private:
        int set[101];

        int validityCheck(int x) const
        {
            return (x >= 0 && x <= 100);
        }
};
