// Приорбанк. Разработать программу, меню которой позволяет выполнить следующие функции
// • Ввод денежной суммы в белорусских рублях
// • Вывод аналогичной суммы в долларах США, евро и российских рублях.
// • Вывод таблицы курсов валют (покупка-продажа, взять данные на день разработки программы).
// • Расчет прибыли от операции для каждой валюты. Определение наиболее выгодной для банка валюты для сделки.
// • Краткая информация о банке и контакты.
// • Выход из программы.

#include <stdio.h>
#include <stdbool.h>

//функция для определения наиболее выгодной валюты
char* currency(float usd, float eur, float rub) {
    if(usd > eur && usd > rub) {
        return "USD";
    }
    else if(rub > usd && rub > eur) {
        return "RUB";
    }
    else if(eur > usd && eur > rub) {
        return "EUR";
    }
    else {
        return "";
    }
}

int main() {
    int input;
    float money = 0, bynToUsd = 0.48, moneyInUsd, bynToEur = 0.43, moneyInEur, bynToRub = 30.96, moneyInRub, usdToBynBuy = 2.082, eurToBynBuy = 2.334, rubToBynBuy = 0.0315, usdToBynSell = 2.104, eurToBynSell = 2.357, rubToBynSell = 0.0329;
    bool end = false;
    
    printf("1. Ввод денежной суммы в белорусских рублях.\n2. Вывод аналогичной суммы в долларах США, евро и российских рублях.\n3. Вывод таблицы курсов валют (покупка-продажа, взять данные на день разработки программы).\n4. Расчет прибыли от операции для каждой валюты. Определение наиболее выгодной для банка валюты для сделки.\n5. Краткая информация о банке и контакты.\n6. Выход из программы.\n");
    
    while(!end) {
        printf("\nВыберите пункт меню: ");
        scanf("%d", &input);
        switch (input) {
            case 1:
                printf("\nВведите сумму в белорусских рублях: ");
                scanf("%g", &money);
                break;
                
            case 2:
                if(money != 0) {
                    moneyInUsd = money * bynToUsd;
                    moneyInEur = money * bynToEur;
                    moneyInRub = money * bynToRub;
                    
                    printf("\nСумма в долларах США: %g", moneyInUsd);
                    printf("\nСумма в евро: %g", moneyInEur);
                    printf("\nСумма в российских рублях: %g\n", moneyInRub);
                }
                else {
                    printf("\nВы ещё не ввели сумму.\n");
                }
                break;
                
            case 3:
                printf("\nКурсы валют\nПокупка:\n");
                printf("1 USD: %g\n1 EUR: %g\n1 RUB: %g\n\n", usdToBynBuy, eurToBynBuy, rubToBynBuy);
                printf("Продажа:\n");
                printf("1 USD: %g\n1 EUR: %g\n1 RUB: %g\n\n", usdToBynSell, eurToBynSell, rubToBynSell);
                break;
                
            case 4:
                printf("\nПрибыль от операции с USD: %g\nПрибыль от операции с EUR: %g\nПрибыль от операции с RUB: %g", usdToBynSell - usdToBynBuy, eurToBynSell - eurToBynBuy, rubToBynSell - rubToBynBuy);
                
                printf("\nНаиболее выгодная для банка валюта для сделки: %s\n", currency(usdToBynSell - usdToBynBuy, eurToBynSell - eurToBynBuy, rubToBynSell - rubToBynBuy));
                break;
                
            case 5:
                printf("\n«Приорбанк» — белорусский коммерческий банк.\nОсновным бенефициарным собственником «Приорбанк» ОАО является Raiffeisen\nLandesbanken Holding AG — дочерняя компания Raiffeisen Bank International AG.\n«Приорбанк» — универсальный банк, предоставляющий широкий спектр банковских услуг.\nКонтакты: +375 17 289 90 90; Velcom, МТС, life: 487\n");
                break;
                
            case 6:
                end = true;
                break;
                
            default:
                printf("\nПроверьте ввод и повторите попытку.\n");
                break;
        }
    }
    return 0;
}
