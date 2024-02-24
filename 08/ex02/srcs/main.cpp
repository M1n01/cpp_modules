#include "../includes/MutantStack.hpp"
#include <iostream>

int main()
{
    MutantStack<int> mstack;

    // 数値を追加
    mstack.push(5);
    mstack.push(17);
    std::cout << "Top element: " << mstack.top() << std::endl; // 最後に追加した要素を表示

    mstack.pop();                                                        // 最後の要素を削除
    std::cout << "Stack size after pop: " << mstack.size() << std::endl; // サイズを表示

    // さらに数値を追加
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    // イテレータを使用してスタックの内容を表示
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    std::cout << "Stack contents: ";
    while (it != ite)
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;

    // コピー構築子と代入演算子のテスト
    MutantStack<int> s(mstack);
    MutantStack<int> s2;
    s2 = s;

    // s2の内容を表示
    std::cout << "Copy assigned stack contents: ";
    for (MutantStack<int>::iterator it = s2.begin(); it != s2.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
