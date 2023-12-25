#pragma once


namespace util
{

  // Stringify is an interface for converting objects to strings.

    template <typename T>
    class Stringify
    {
    public:
        virtual std::string toString() const = 0;
        friend std::ostream &operator<<(std::ostream &os, const T &stringify)
        {
            return os << stringify.toString();
        }
    };

} // namespace util