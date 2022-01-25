int stocks[n][2][K + 1];

for (int trans = 0; trans <= K; trans++)
{

    stocks[n - 1][0][trans] = 0;

    if (trans == 0)
        stocks[n - 1][1][trans] = 0;
    else
        stocks[n - 1][1][trans] = prices[n - 1];
}

for (int days = n - 2; days >= 0; days--)
{
    for (int trans = 0; trans <= K; trans++)
    {
        // Case 1: don't own
        stocks[days][0][trans] = max((-prices[days] + stocks[days + 1][1][trans]), stocks[days + 1][0][trans]);

        // Case 2: own
        if (trans == 0)
            stocks[days][1][trans] = max(0, stocks[days + 1][1][trans]);
        else
            stocks[days][1][trans] = max(prices[days] + stocks[days + 1][0][trans - 1], stocks[days + 1][1][trans]);
    }
}

return stocks[0][0][K];
}
}
;
