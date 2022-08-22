foo(
    p1
    );

foo(bar(
    p1
    )
    );

foo(bar(baz(
    p1)
    )
    );

foo(bar(
    baz(
        p1)
    )
    );

foo(
    bar(baz(
        p1)
        )
    );

foo(
    bar(
        baz(
            p1)
        )
    );

foo(
    p1,
    bar(
        p2,
        baz(
            p3
            )
        )
    );

foo(p1,
    bar(p2,
        p3
        )
    );

namespace ns
{
foo(p1
    , p2
    , [](a, b) {
        bar(p3
            , p4
            );
    });
}
