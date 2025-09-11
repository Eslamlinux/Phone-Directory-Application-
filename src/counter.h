

void Counter_from_to_(int start, int end) {
    if (start > end) {
        return ; // Return 0 if the range is invalid
    }
    for (int i = start; i <= end; ++i) {
        std::cout << i << " ";
    }
}