template< typename T, typename U >
struct pair {
    using first_type = T;
    using second_type = U;
    T first;
    U second;
    pair();
    pair(T const& first, U const& second);
    template< typename T2, typename U2 >
    pair(pair<T2, U2> const& other);
};

template<>
struct pair<void, void> {
    using first_type = void;
    using second_type = void;
    pair(pair const&) = default;
    pair() = default;
    pair& operator=(pair const&) = default;
};

template< typename U >
struct pair<void, U> {
    using first_type = void;
    using second_type = U;
    U second;
    pair() = default;
    pair(pair const&) = default;
    pair(U const& second) : second{second} {}
    template<class U2>
    pair(pair<void, U2> const& other);
};

template< typename T >
struct pair<T, void> {
    using first_type = T;
    using second_type = void;
    T first;
    pair() = default;
    pair(pair const&) = default;
    pair(T const& first) : first{first} {}
    template<class T2>
    pair(pair<T2, void> const& other);
};