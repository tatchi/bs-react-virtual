[@react.component]
let make = () => {
  let parentRef = React.useRef(Js.Nullable.null);

  let rowVirtualizer =
    ReactVirtual.useVirtual(
      ReactVirtual.options(
        ~size=10000,
        ~parentRef,
        ~estimateSize=React.useCallback0(_ => 35),
        (),
      ),
    );

  <div
    ref={ReactDOMRe.Ref.domRef(parentRef)}
    style={ReactDOMRe.Style.make(
      ~height="150px",
      ~width="300px",
      ~overflow="auto",
      (),
    )}>
    <div
      style={ReactDOMRe.Style.make(
        ~height={string_of_int(rowVirtualizer.totalSize) ++ "px"},
        ~width="100%",
        ~position="relative",
        (),
      )}>
      {rowVirtualizer.virtualItems
       ->Belt.Array.map(virtualRow =>
           <div
             key={string_of_int(virtualRow.index)}
             style={ReactDOMRe.Style.make(
               ~position="absolute",
               ~top="0px",
               ~left="0px",
               ~width="100%",
               ~height={string_of_int(virtualRow.size) ++ "px"},
               ~transform=
                 {"translateY(" ++ string_of_int(virtualRow.start) ++ "px)"},
               (),
             )}>
             {React.string(
                "Row "
                ++ string_of_int(virtualRow.index)
                ++ " "
                ++ string_of_int(virtualRow.end_),
              )}
           </div>
         )
       ->ReasonReact.array}
    </div>
  </div>;
};