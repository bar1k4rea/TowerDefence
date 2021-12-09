/* Created by bar1k4real on 15.11.2021. */

#ifndef TOWER_DEFENCE_TABLE_H
#define TOWER_DEFENCE_TABLE_H

#include <iostream>
#include <exception>

namespace TowerDefence {

    // Struct Pair
    template<class K, class D>
    struct Pair {
        K key;
        D data;

        Pair();

        Pair(K key, D data);
    };

    // Empty constructor for Pair.
    template<class K, class D>
    Pair<K, D>::Pair() : key(), data() {
//        std::cout << "Empty Constructor for Pair: " << this << std::endl;
    }

    // First constructor for Pair.
    template<class K, class D>
    Pair<K, D>::Pair(K key, D data) : key(key), data(data) {
//        std::cout << "First Constructor for Pair: " << this << std::endl;
    }

    // Input for Pair.
    template<class K, class D>
    std::istream &operator>>(std::istream &in, Pair<K, D> &pair) {
        in >> pair.key >> pair.data;
        return in;
    }

    // Output for Pair.
    template<class K, class D>
    std::ostream &operator<<(std::ostream &out, const Pair<K, D> &pair) {
        out << pair.key << ' ' << pair.data;
        return out;
    }

    // Class TableIterator
    template<class K, class D>
    class TableIterator {
    private:
        Pair<K, D> *m_pair;
    public:
        TableIterator();

        explicit TableIterator(Pair<K, D> *pair);

        bool operator!=(const TableIterator<K, D> &tableIterator) const;

        bool operator==(const TableIterator<K, D> &tableIterator) const;

        Pair<K, D> &operator*();

        TableIterator &operator++();
    };

    // Empty constructor for TableIterator.
    template<class K, class D>
    TableIterator<K, D>::TableIterator() : m_pair(nullptr) {
//        std::cout << "Empty Constructor for TableIterator: " << this << std::endl;
    }

    // Copy constructor for TableIterator.
    template<class K, class D>
    TableIterator<K, D>::TableIterator(Pair<K, D> *pair) : m_pair(pair) {
//        std::cout << "Copy Constructor for TableIterator: " << this << std::endl;
    }

    template<class K, class D>
    Pair<K, D> &TableIterator<K, D>::operator*() {
        if (m_pair)
            return *m_pair;
        throw std::invalid_argument("Illegal value for Table Iterator!");
    }

    template<class K, class D>
    TableIterator<K, D> &TableIterator<K, D>::operator++() {
        ++m_pair;
        return *this;
    }

    template<class K, class D>
    bool TableIterator<K, D>::operator!=(const TableIterator<K, D> &tableIterator) const {
        return m_pair != tableIterator.m_pair;
    }

    template<class K, class D>
    bool TableIterator<K, D>::operator==(const TableIterator<K, D> &tableIterator) const {
        return m_pair == tableIterator.m_pair;
    }

    // Class Table.
    template<class K, class D>
    class Table {
    private:
        static const int BLOCK = 5;
        int m_counter;
        Pair<K, D> *m_array;
    public:
        Table();

        Table(int counter, const Pair<K, D> *array);

        Table(const Table<K, D> &table);

        Table(Table<K, D> &&table) noexcept;

        ~Table();

        Table &operator=(const Table<K, D> &table);

        Table &operator=(Table<K, D> &&table) noexcept;

        void push(const Pair<K, D> &pair);

        D &find(const K &key);

        D &operator[](const K &key);

        [[nodiscard]] int getCounter() const;

        friend class TableIterator<K, D>;

        TableIterator<K, D> begin();

        TableIterator<K, D> end();
    };

    // Empty constructor for Table.
    template<class K, class D>
    Table<K, D>::Table() : m_counter(0), m_array(nullptr) {
//        std::cout << "Empty Constructor for Table: " << this << std::endl;
    }

    // First constructor for Table.
    template<class K, class D>
    Table<K, D>::Table(int counter, const Pair<K, D> *array) : m_counter(counter) {
        if (!m_counter)
            m_array = nullptr;
        else {
            m_array = new Pair<K, D>[BLOCK * ((m_counter - 1) / BLOCK + 1)];
            for (int i = 0; i < m_counter; i++)
                m_array[i] = array[i];
        }
//        std::cout << "First Constructor for Table: " << this << std::endl;
    }

    // Copy constructor for Table.
    template<class K, class D>
    Table<K, D>::Table(const Table<K, D> &table) : m_counter(table.m_counter) {
        if (!m_counter)
            m_array = nullptr;
        else {
            m_array = new Pair<K, D>[BLOCK * ((m_counter - 1) / BLOCK + 1)];
            for (int i = 0; i < m_counter; i++)
                m_array[i] = table.m_array[i];
        }
//        std::cout << "Copy Constructor for Table: " << this << std::endl;
    }

    // Move constructor for Table.
    template<class K, class D>
    Table<K, D>::Table(Table<K, D> &&table) noexcept : m_counter(table.m_counter), m_array(table.m_array) {
        table.m_counter = 0;
        table.m_array = nullptr;
//        std::cout << "Move Constructor for Table: " << this << std::endl;
    }

    // Destructor for Table.
    template<class K, class D>
    Table<K, D>::~Table() {
        m_counter = 0;
        delete[] m_array;
//        std::cout << "Destructor for Table: " << this << std::endl;
    }

    // Copy assignment operator for Table.
    template<class K, class D>
    Table<K, D> &Table<K, D>::operator=(const Table<K, D> &table) {
        if (this != &table) {
            delete[] m_array;
            m_counter = table.m_counter;
            if (!m_counter)
                m_array = nullptr;
            else {
                m_array = new Pair<K, D>[BLOCK * ((m_counter - 1) / BLOCK + 1)];
                for (int i = 0; i < m_counter; i++)
                    m_array[i] = table.m_array[i];
            }
        }
//        std::cout << "Copy Assignment Operator for Table: " << this << " = " << &table << std::endl;
        return *this;
    }

    // Move assignment operator for Table.
    template<class K, class D>
    Table<K, D> &Table<K, D>::operator=(Table<K, D> &&table) noexcept {
        if (this != &table) {
            delete[] m_array;
            m_counter = table.m_counter;
            m_array = table.m_array;
            table.m_counter = 0;
            table.m_array = nullptr;
        }
//        std::cout << "Move Assignment Operator for Table: " << this << " = " << &table << std::endl;
        return *this;
    }

    // Add Pair.
    template<class K, class D>
    void Table<K, D>::push(const Pair<K, D> &pair) {
        if (!(m_counter % BLOCK)) {
            Pair<K, D> *array;
            array = new Pair<K, D>[BLOCK * (m_counter / BLOCK + 1)];
            for (int i = 0; i < m_counter; i++)
                array[i] = m_array[i];
            delete[] m_array;
            array[m_counter++] = pair;
            m_array = array;
        } else
            m_array[m_counter++] = pair;
    }

    // Find data in Pair.
    template<class K, class D>
    D &Table<K, D>::find(const K &key) {
        for (int i = 0; i < m_counter; i++)
            if (key == m_array[i].key)
                return m_array[i].data;
    }

    // Indexing operator.
    template<class K, class D>
    D &Table<K, D>::operator[](const K &key) {
        return find(key);
    }

    // Getter for m_counter.
    template<class K, class D>
    int Table<K, D>::getCounter() const {
        return m_counter;
    }

    template<class K, class D>
    TableIterator<K, D> Table<K, D>::begin() {
        return TableIterator<K, D>(m_array);
    }

    template<class K, class D>
    TableIterator<K, D> Table<K, D>::end() {
        return TableIterator<K, D>(m_array + m_counter);
    }

} /* namespace TowerDefence */

#endif /* TOWER_DEFENCE_TABLE_H */