#pragma once

class StockProducto
{
    public:
        StockProducto() {};

        void setId(int id);
        void setStock(int stock);

        int getId();
        int getStock();

    private:
        int _id;
        int _stock;
};
