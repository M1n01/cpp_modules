#include "../includes/Span.hpp"
#include <iostream>

int main()
{
    try
    {
        // Spanクラスのインスタンスを作成し、5つの数値を格納できるようにします
        Span sp = Span(5);

        // 数値を追加します
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        // 最短と最長のスパンを出力します
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;

        // Spanの容量を超える数値を追加しようとすると、例外が発生します
        sp.addNumber(12);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // 大量の数値を扱うテスト
    try
    {
        Span sp(10000); // 例として10000までの数値を追加できるようにします

        // 1から10000までの数値のベクターを作成
        std::vector<int> largeNumbers;
        for (int i = 1; i <= 10000; ++i)
        {
            largeNumbers.push_back(i);
        }

        // addNumbersを使って一度の呼び出しで数値を追加
        sp.addNumbers(largeNumbers.begin(), largeNumbers.end());

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
