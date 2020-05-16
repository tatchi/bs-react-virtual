[@react.component]
let make = () => {
  let parentRef = React.useRef(Js.Nullable.null);

  let rowVirtualizer =
    ReactVirtual.useVirtual(
      ReactVirtual.options(
        ~size=10000,
        ~parentRef,
        ~estimateSize=React.useCallback0(_ => 35),
        ~scrollToFn=(offset, defaultScrollToFn) => defaultScrollToFn(offset),
        (),
      ),
    );

  <div>
    <button
      onClick={_ =>
        rowVirtualizer->ReactVirtual.scrollToIndex(
          ~index=0,
          ~options={align: ReactVirtual.Align.auto},
          (),
        )
      }>
      {React.string("ScrollToIndex")}
    </button>
    <button
      onClick={_ =>
        rowVirtualizer->ReactVirtual.scrollToOffset(
          ~offset=100,
          ~options={align: ReactVirtual.Align.auto},
          (),
        )
      }>
      {React.string("ScrollToOffset")}
    </button>
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
               ref={ReactDOMRe.Ref.domRef(virtualRow.measureRef)}
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
               {React.string("Row " ++ string_of_int(virtualRow.index))}
             </div>
           )
         ->ReasonReact.array}
      </div>
    </div>
  </div>;
};