/*
Version 1
template <typename TipoRetorno, typename T, typename U>
TipoRetorno add(const T& t, const U& u) {
    return t + u;
}
*/

/*
Version 2
template <typename TipoRetorno = long, typename T, typename U>
TipoRetorno add(const T& t, const U& u) {
    return t + u;
}
*/

/*
Version 3
template <typename T, typename U>
auto add(const T& t, const U& u) {
    return t + u;
}
*/

/*
Version 4
template <typename T, typename U>
decltype(auto) add(const T& t, const U& u) {
    return t + u;
}
*/

decltype(auto) add(const auto& t, const auto& u) {
    return t + u;
}

int main() {
    // auto resultado{add(3, 5)}; // no funciona
    auto resultado{add(3, 5)}; // sí funciona
}
